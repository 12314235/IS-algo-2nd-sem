#include <iostream>
#include <string>

#define int unsigned long long
#define p 23
#define m 10000000000000000007

int H(const std::string::iterator& s, const std::string::iterator& e) {
    int h = 0;
    int X = 1;
    for(std::string::iterator i = e - 1; i >= s; i--) {
        h += (*i) * X;
        X *= p;
    }

    return h % m;
}

signed main() {
    int N, M;
    std::cin >> N >> M;

    std::string text;

    std::cin >> text;

    int i, j, k;

    int res = 0;

    for(int s = 0; s < M; s++) {
        std::cin >> i >> j >> k;
        i--;
        j--;

        int h1 = H(text.begin() + i, text.begin() + i + k);

        int h2 = H(text.begin() + j, text.begin() + j + k);

        if(h1 == h2) res++;
    }

    std::cout << res;

    return 0;
}
