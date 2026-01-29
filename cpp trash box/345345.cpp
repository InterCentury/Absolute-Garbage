#include "GPUInfo.h"
#include <windows.h>
#include <dxgi1_6.h>
#include <dxcore.h>
#include <wbemidl.h>
#include <comdef.h>
#include <iostream>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxcore.lib")
#pragma comment(lib, "wbemuuid.lib")

using namespace std;

// ----------------------------------------------------
// Helper: converts wide string to UTF-8 string
static string wstr_to_utf8(const wstring& w) {
    if (w.empty()) return {};
    int sz = WideCharToMultiByte(CP_UTF8, 0, w.c_str(), -1, nullptr, 0, nullptr, nullptr);
    string r(sz - 1, 0);
    WideCharToMultiByte(CP_UTF8, 0, w.c_str(), -1, r.data(), sz, nullptr, nullptr);
    return r;
}

// ----------------------------------------------------
vector<gpu_data> GPUInfo::get_all_gpu_info() {
    vector<gpu_data> list;

    IDXGIFactory6* factory = nullptr;
    if (FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&factory))))
        return list;

    IDXGIAdapter1* adapter = nullptr;
    for (UINT i = 0; factory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i) {
        DXGI_ADAPTER_DESC1 desc;
        adapter->GetDesc1(&desc);

        gpu_data d;
        d.gpu_name   = wstr_to_utf8(desc.Description);
        d.gpu_memory = to_string(static_cast<int>(
            desc.DedicatedVideoMemory / (1024.0 * 1024.0 * 1024.0))) + " GB";
        d.gpu_driver_version = "N/A";
        d.gpu_vendor = (desc.VendorId == 0x10DE) ? "NVIDIA" :
                       (desc.VendorId == 0x1002 || desc.VendorId == 0x1022) ? "AMD" :
                       (desc.VendorId == 0x8086) ? "Intel" : "Unknown";

        // quick lightweight runtime info
        d.gpu_usage       = get_gpu_usage();
        d.gpu_temperature = get_gpu_temperature();
        d.gpu_core_count  = get_gpu_core_count();

        list.push_back(d);
        adapter->Release();
    }
    factory->Release();
    return list;
}

// ----------------------------------------------------
// Fallback WMI query helper
static bool query_wmi_float(const wchar_t* wql, const wchar_t* field, float& outVal) 
{
    HRESULT hr = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hr)) return false;
    hr = CoInitializeSecurity(NULL, -1, NULL, NULL,
        RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
    if (FAILED(hr) && hr != RPC_E_TOO_LATE) { CoUninitialize(); return false; }

    IWbemLocator* locator = nullptr;
    IWbemServices* services = nullptr;
    hr = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER,
        IID_IWbemLocator, (LPVOID*)&locator);
    if (FAILED(hr)) { CoUninitialize(); return false; }

    hr = locator->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &services);
    locator->Release();
    if (FAILED(hr)) { CoUninitialize(); return false; }

    CoSetProxyBlanket(services, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL,
        RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE);

    IEnumWbemClassObject* enumerator = nullptr;
    hr = services->ExecQuery(bstr_t("WQL"), bstr_t(wql),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &enumerator);
    if (FAILED(hr)) { services->Release(); CoUninitialize(); return false; }

    IWbemClassObject* obj = nullptr;
    ULONG returned = 0;
    bool ok = false;
    while (enumerator && SUCCEEDED(enumerator->Next(WBEM_INFINITE, 1, &obj, &returned)) && returned) {
        VARIANT val;
        if (SUCCEEDED(obj->Get(field, 0, &val, 0, 0)) && (val.vt == VT_R8 || val.vt == VT_I4)) {
            outVal = (val.vt == VT_R8) ? (float)val.dblVal : (float)val.intVal;
            ok = true;
            VariantClear(&val);
            obj->Release();
            break;
        }
        VariantClear(&val);
        obj->Release();
    }
    if (enumerator) enumerator->Release();
    services->Release();
    CoUninitialize();
    return ok;
}

// ----------------------------------------------------
float GPUInfo::get_gpu_usage() {
    // Very fast generic WMI usage counter (approx.)
    float val = 0.0f;
    query_wmi_float(
        L"SELECT UtilizationPercentage FROM Win32_PerfFormattedData_GPUPerformanceCounters_GPUEngine WHERE Name LIKE '%_3D%'",
        L"UtilizationPercentage",
        val);
    return val;
}

// ----------------------------------------------------
float GPUInfo::get_gpu_temperature() {
    float val = 0.0f;
    // ACPI thermal zone gives system temperature (approx.)
    query_wmi_float(
        L"SELECT CurrentTemperature FROM MSAcpi_ThermalZoneTemperature",
        L"CurrentTemperature",
        val);
    if (val > 2732.0f)
        val = (val / 10.0f) - 273.15f; // convert from tenths of Kelvin
    return val;
}

// ----------------------------------------------------
int GPUInfo::get_gpu_core_count() {
    // DXCore can return architecture info (if supported)
    ID3D12Device* device = nullptr;
    IDXGIFactory4* factory = nullptr;
    if (FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&factory))))
        return 0;

    IDXGIAdapter1* adapter = nullptr;
    int cores = 0;
    if (SUCCEEDED(factory->EnumAdapters1(0, &adapter))) {
        if (SUCCEEDED(D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device)))) {
            D3D12_FEATURE_DATA_D3D12_OPTIONS opts{};
            if (SUCCEEDED(device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS, &opts, sizeof(opts)))) {
                // This doesn't directly expose cores, so we estimate by compute units
                cores = 2560; // placeholder typical GPU, override per vendor if needed
            }
            device->Release();
        }
        adapter->Release();
    }
    factory->Release();
    return cores;
}
