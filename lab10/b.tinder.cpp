#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;

void dfs(int current, int finish) {
    visited[current] = true;
    if (current == finish) return;

    for (auto i: graph[current]) {
        if (!visited[i]) dfs(i, finish);
    }
}

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    graph.assign(n, {});
    visited.assign(n, false);

    int kun, tyan;

    for (int i = 0; i < m; i++) {
        std::cin >> kun >> tyan;

        graph[kun - 1].emplace_back(tyan - 1);
        graph[tyan - 1].emplace_back(kun - 1);
    }

    char command;

    for (int i = 0; i < q; i++) {
        std::cin >> command >> kun >> tyan;
        kun--;
        tyan--;
        switch (command) {
            case '?':
                dfs(kun, tyan);
                std::cout << (visited[tyan] ? "YES" : "NO") << '\n';
                visited.assign(n, false);
                break;
            case '-':
                for (int j = 0; j < graph[kun].size(); j++) {
                    if (graph[kun][j] == tyan) graph[kun].erase(graph[kun].begin() + j);
                }
                for (int j = 0; j < graph[tyan].size(); j++) {
                    if (graph[tyan][j] == kun) graph[tyan].erase(graph[tyan].begin() + j);
                }
                break;
        }
    }
}
