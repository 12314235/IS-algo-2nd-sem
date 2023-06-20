#include <iostream>
#include <vector>

struct Edge{
    int x;
    int y;
    int w;

    Edge(int x, int y, int w){
        this->x = x;
        this->y = y;
        this->w = w;
    }
};

int main() {
    int N, k;

    std::cin >> N >> k;

    std::vector<Edge*> graph;
    std::vector<int> parents;
    std::vector<int> visited;
    std::vector<long long> d;

    int n, m;
    int start, end, w;

    int x;

    for(int i = 0; i < N; i++) {
        std::cin >> n >> m;

        parents.assign(n, -1);
        d.assign(n, INT64_MAX);
        visited.assign(n, 0);

        for(int j = 0; j < m; j++){
            std::cin >> start >> end >> w;
            start--;
            end--;
            graph.emplace_back(new Edge(start, end, w));
        }

        d[0] = 0;

        for(int l = 0; l < n; ++l) {
            x = -1;
            for (auto b: graph) {
                if(d[b->x] == INT64_MAX) continue;
                if (d[b->y] > d[b->x] + b->w) {
                    d[b->y] = d[b->x] + b->w;
                    parents[b->y] = b->x;
                    x = b->y;
                }
            }
            if(x == -1) break;
        }

        int y;
        int weight = 0;

        if(x == -1){
            std::cout << "YES\n";
        } else {
            visited[x]++;
            y = parents[x];
            weight = 0;
            for(int a = 0; a < n; a++) {
                if(visited[y] == 1) break;
                visited[y]++;
                y = parents[y];
            }

            while(visited[y] != 2) {
                visited[y]++;
                y = parents[y];
                weight++;
            }

            if(weight <= k) {
                std::cout << "YES" << '\n';
            } else {
                std::cout << "NO" << '\n';
            }

        }

        graph.clear();
    }
}
