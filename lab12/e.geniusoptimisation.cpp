#include <vector>
#include <iostream>

#define int long long

struct Edge {
    int v;
    int flow;
    int capacity;

    Edge(int v, int capacity) : v(v), flow(0), capacity(capacity) {}

    int propusk() {
        return capacity - flow;
    }
};

int S, T;

std::vector<Edge> edges;
std::vector<std::vector<int>> graph;
std::vector<int> used;
int timer = 1;

int dfs(int v, int min_capacity) {
    if (v == T) {
        return min_capacity;
    }
    used[v] = timer;
    for (int neighbor : graph[v]) {
        if (edges[neighbor].propusk() == 0) {
            continue;
        }
        if (used[edges[neighbor].v] == timer) {
            continue;
        }
        int x = dfs(edges[neighbor].v, std::min(min_capacity, edges[neighbor].propusk()));
        if (x) {
            edges[neighbor].flow += x;
            edges[neighbor ^ 1].flow -= x;
            return x;
        }
    }

    return 0;
}

signed main() {
    int n, m;
    std::cin >> n >> m;

    S = 0;
    T = n - 1;

    graph.assign(n, std::vector<int>());
    used.assign(n, false);

    for (int i = 0; i < m; ++i) {
        int v, u, capacity;
        std::cin >> v >> u >> capacity;
        v--;
        u--;
        graph[v].emplace_back(edges.size());
        edges.emplace_back(u, capacity);
        graph[u].emplace_back(edges.size());
        edges.emplace_back(v, 0);
    }
    while (dfs(S, INT64_MAX)) {
        ++timer;
    }

    int result = 0;
    for (int index : graph[S]) {
        result += edges[index].flow;
    }

    std::cout << result << '\n';
    return 0;
}
