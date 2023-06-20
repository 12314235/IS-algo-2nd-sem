#include <iostream>
#include <vector>

#define int long long

int N;

int h(int k) {
    return (k % 239) % (2 * N);
}

int g(int k) {
    return 1 + k % ((2 * N) - 1);
}

int H(int k, int i) {
    return (h(k) + i * g(k)) % (2 * N);
}

signed main() {
    std::cin >> N;

    int x, j;

    std::vector<int> a(2 * N, -1);

    for(int i = 0; i < N; i++) {
        std::cin >> x;

        for(int j = 0; j < 2 * N; j++) {
            if(a[H(x, j)] == -1) {
                a[H(x, j)] = x;
                break;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cin >> x;

        for(int j = 0; j < 2 * N && a[H(x, j)] != x; j++) {
            if(a[H(x, j)] == -1) {
                std::cout << "NO";
                return 0;
            }
        }
    }

    std::cout << "YES";
    return 0;
}
