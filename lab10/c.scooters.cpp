#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
bool* visited;
bool f;

void dfs(int current, int finish) {
    visited[current] = true;
    if (current == finish) {
        f = true;
        return;
    }

    for (auto i: graph[current]) {
        if (!visited[i]) dfs(i, finish);
        if(f) return;
    }
}

int main() {
    int n, m, q;

    std::cin >> n >> m >> q;

    graph.assign(n, {});

    int start, end;

    for(int i = 0; i < m; i++){
        std::cin >> start >> end;

        graph[start - 1].emplace_back(end - 1);
    }

    bool f1;
    visited = new bool[n];

    for(int i = 0; i < q; i++){
        std::cin >> start >> end;
        start--;
        end--;
        f = false;
        for(int j = 0; j < n; j++){
            visited[j] = false;
        }
        dfs(start, end);
        f1 = f;
        f = false;
        for(int j = 0; j < n; j++){
            visited[j] = false;
        }
        dfs(end, start);
        std::cout << (f && f1 ? "YES" : "NO") << '\n';
    }
}
