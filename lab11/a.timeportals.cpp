#include <iostream>
#include <vector>

int main() {
    int M;
    int N, K;

    std::cin >> N >> M >> K;

    int x, y;
    size_t w;

    std::vector<std::vector<size_t>> graph;

    graph.assign(N, std::vector<size_t>(N, INT64_MAX));

    for (int i = 0; i < M; ++i) {
        std::cin >> x >> y >> w;

        graph[x - 1][y - 1] = w;
    }

    for (int pivot = 0; pivot < N; ++pivot) {
        for (int from = 0; from < N; ++from) {
            for (int to = 0; to < N; ++to) {
                if (abs(pivot - from) <= K && abs(pivot - to) <= K) {
                    graph[from][to] = std::min(graph[from][to], graph[from][pivot] + graph[pivot][to]);
                }
            }
        }
    }

    int Q;

    std::cin >> Q;

    for (int i = 0; i < Q; ++i) {
        std::cin >> x >> y;

        if (graph[x - 1][y - 1] == INT64_MAX) {
            std::cout << -1 << '\n';
        } else {
            std::cout << graph[x - 1][y - 1] << '\n';
        }
    }

    return 0;
}
