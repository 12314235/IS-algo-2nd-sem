#include <iostream>
#include <regex>
#include <string>

signed main() {
    std::string data;

    int counter;

    std::cin >> counter;
    std::getline(std::cin, data);

    std::regex a(R"(([A-Z][a-z]+\s){3}\d{2}\s(\+7|7|8)((\(\d{3}\)-?)|\d{3})\d{3}-?\d{2}-?\d{2}\sg\.[A-Z]{3},?\sul\.[A-Z][a-z]+,?\sd\.\d+)");

    int k = 0;

    for(int i = 0; i < counter; i++) {
        std::getline(std::cin, data);
        std::cout << (!std::regex_match(data, a) ? "NO" : "YES") << '\n';
    }
}
