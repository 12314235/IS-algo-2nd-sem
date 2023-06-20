#include <iostream>
#include <vector>

int main() {
    int M;
    int N;

    std::cin >> N >> M;

    if (M == 0) {
        std::cout << 0;
        return 0;
    }


    int x, y;
    size_t w;

    std::vector<std::vector<size_t>> graph;

    graph.assign(N, std::vector<size_t>(N, INT64_MAX));

    for (int i = 0; i < M; ++i) {
        std::cin >> x >> y >> w;

        graph[x - 1][y - 1] = w;
        graph[y - 1][x - 1] = w;
    }

    size_t max_dist = 0;

    for(int  i = 0; i < N; i++){
        graph[i][i] = 0;
    }

    for (int pivot = 0; pivot < N; ++pivot) {
        for (int from = 0; from < N; ++from) {
            for (int to = 0; to < N; ++to) {
                if (graph[from][to] > graph[from][pivot] + graph[pivot][to]) {
                    graph[from][to] = graph[from][pivot] + graph[pivot][to];
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(graph[i][j] != INT64_MAX) {
                max_dist = std::max(graph[i][j], max_dist);
            }
        }
    }

    std::cout << max_dist;

    return 0;
}
