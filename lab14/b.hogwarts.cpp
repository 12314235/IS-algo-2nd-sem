#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string spell;

    std::cin >> spell;

    std::vector<int> p(spell.size() + 1, 0);
    p[0] = -1;

    for(int i = 1; i <= spell.size(); i++) {
        int k = p[i - 1];
        while(k != -1 && spell[k] != spell[i - 1]) {
            k = p[k];
        }
        p[i] = k + 1;
    }

    for(int i = 1; i < p.size(); i++) {
        std::cout << p[i] << ' ';
    }
}
