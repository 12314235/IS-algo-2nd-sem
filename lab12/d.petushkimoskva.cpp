#include <iostream>
#include <vector>

#define int long long

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> table;
std::vector<bool> used;
std::vector<int> mt;

bool kun(int vertex) {
    if (used[vertex]) return false;

    used[vertex] = true;
    for (auto i: graph[vertex]) {
        if (mt[i] == -1 || kun(mt[i])) {
            mt[i] = vertex;
            return true;
        }
    }

    return false;
}

signed main() {
    int N, M;

    std::cin >> N >> M;

    table.assign(N, std::vector<int>(M, 1));

    int k1 = 0, k2 = 0;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if((i + j) % 2 == 0) {
                table[i][j] = k2;
                k2++;
            }
            else {
                table[i][j] = k1;
                k1++;
            }
        }
    }

    graph.assign(k1, std::vector<int>(0, 0));

    int Q;

    std::cin >> Q;

    std::vector<bool> banned(N * M + 1);

    int x, y;

    for (int i = 0; i < Q; i++) {
        std::cin >> x >> y;
        table[x - 1][y - 1] = INT64_MAX;
    }

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(table[i][j] != INT64_MAX) {
                if((i + j) % 2 != 0) {
                    if(i > 0 && table[i - 1][j] != INT64_MAX) {
                        graph[table[i][j]].emplace_back(table[i - 1][j]);
                    }
                    if(j > 0 && table[i][j - 1] != INT64_MAX) {
                        graph[table[i][j]].emplace_back(table[i][j - 1]);
                    }
                    if(j < M - 1 && table[i][j + 1] != INT64_MAX) {
                        graph[table[i][j]].emplace_back(table[i][j + 1]);
                    }
                    if(i < N - 1 && table[i + 1][j] != INT64_MAX) {
                        graph[table[i][j]].emplace_back(table[i + 1][j]);
                    }
                }
            }
        }
        /*graph.emplace_back(i, std::vector<int>());
        if (i - N > 0 && !banned[i - N]) graph.back().second.push_back(i - N);
        if (i + N <= N * M && !banned[i + N]) graph.back().second.push_back(i + N);
        if (i % N != 0 && !banned[i + 1]) graph.back().second.push_back(i + 1);
        if ((i - 1) % N != 0 && !banned[i - 1]) graph.back().second.push_back(i - 1);*/
    }

    mt.assign(k2, -1);

    int res = 0;

    for (int i = 0; i < graph.size(); i++) {
        used.assign(banned.begin(), banned.end());

        res += kun(i) ? 1 : 0;
    }

    std::cout << res * 2;
}
