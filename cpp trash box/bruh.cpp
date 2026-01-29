#include <iostream>
#include <string>
#include <map>

using namespace std;

// ANSI color codes
map<string, string> colors = {
    {"black", "\033[30m"}, {"red", "\033[31m"}, {"green", "\033[32m"}, 
    {"yellow", "\033[33m"}, {"blue", "\033[34m"}, {"magenta", "\033[35m"}, 
    {"cyan", "\033[36m"}, {"white", "\033[37m"}, {"reset", "\033[0m"}
};

void printColored(const string& text, const string& color) {
    cout << colors[color] << text << colors["reset"];
}

int main() {
    // Example usage
    string headingColor = "cyan";
    string titleColor = "yellow";
    string infoColor = "green";
    string artColor = "blue";

    // Heading
    printColored("coffee~@Maruf\n", headingColor);

    // ASCII Art
    printColored("/// ASCII ART ///\n", artColor);

    // Info lines
    printColored("OS: ", titleColor);
    printColored("Windows 11 Pro x86_64\n", infoColor);

    printColored("CPU: ", titleColor);
    printColored("AMD Ryzen 5 5600G\n", infoColor);

    return 0;
}
