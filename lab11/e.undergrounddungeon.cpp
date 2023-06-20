#include <iostream>
#include <vector>

struct Edge{
    int y;
    int w;

    Edge(int y, int w){
        this->y = y;
        this->w = w;
    }
};

int N;

std::vector<std::vector<Edge*>> graph;
std::vector<int> sorted;
std::vector<size_t> d;
std::vector<bool> visited;

void dfs(int vertex) {
    visited[vertex] = true;
    for(auto i : graph[vertex]) {
        if (!visited[i->y]) {
            dfs(i->y);
        }
    }

    sorted.push_back(vertex);
}

void top_sort() {
    visited.assign(N, false);
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int M;

    std::cin >> N >> M;

    int S, T;

    for(int i = 0; i < N; i++){
        graph.push_back({});
    }

    d.assign(N, INT64_MAX);

    std::cin >> S >> T;

    S--;
    T--;

    int x, y, w;

    for(int i = 0; i < M; i++) {
        std::cin >> x >> y >> w;
        x--;
        y--;

        graph[x].push_back(new Edge(y, w));
    }

    top_sort();
    int vertex;

    d[S] = 0;

    for(int i = N - 1; i >= 0; i--) {
        vertex = sorted[i];
        for (auto p: graph[vertex]) {
            if(d[p->y] > d[vertex] + p->w){
                d[p->y] = d[vertex] + p->w;
            }
        }
    }

    if(d[T] == INT64_MAX) {
        std::cout << -1;
    } else {
        std::cout << d[T];
    }

    return 0;
}
