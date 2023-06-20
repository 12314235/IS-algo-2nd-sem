#include <iostream>
#include <string>
#include <vector>

signed main() {
    std::string text;
    std::string name;

    std::cin >> text;

    std::cin >> name;

    text = name + '#' + text;

    std::vector<int> p(text.size() + 1, 0);
    p[0] = -1;

    for(int i = 1; i <= text.size(); i++) {
        int k = p[i - 1];
        while(k != -1 && text[k] != text[i - 1]) {
            k = p[k];
        }
        p[i] = k + 1;
    }

    std::vector<int> ans;
    int counter = 0;

    for(int i = 0; i < p.size(); i++) {
        if(p[i] == name.size()) {
            counter++;
            ans.push_back(i - name.size() * 2 - 1);
        }
    }

    std::cout << counter << '\n';

    for(auto i : ans) {
        std::cout << i << ' ';
    }
}
