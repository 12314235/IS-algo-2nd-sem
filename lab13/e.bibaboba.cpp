#include <iostream>
#include <vector>

#define int long long

int N;

int C(int x) {
    return ((x - 1) * x) / 2;
}

std::vector<std::vector<int>> table;

int h(int k) {
    return (k + 100000000) % (3 * N);
}

signed main() {

    std::cin >> N;

    int x;

    table.assign(3 * N, std::vector<int>());

    for(int i = 0; i < N; i++) {
        std::cin >> x;

        table[h(x - i)].push_back(x);
    }

    int res = 0;

    for(auto i : table) {
        res += C(i.size());
    }

    std::cout << res;


}
