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
    int M, Q, Start;

    std::vector<Edge*> graph;
    std::vector<size_t> d;
    int N;

    std::cin >> N >> M >> Q >> Start;

    Start--;

    d.assign(N, INT64_MAX);

    int s, e, w;

    for(int i = 0; i < M; i++) {
        std::cin >> s >> e >> w;

        s--;
        e--;

        graph.push_back(new Edge(s, e, w));
        graph.push_back(new Edge(e, s, w));
    }

    d[Start] = 0;

    int x;

    for(int k = 0; k < N - 1; ++k) {
        x = -1;
        for (auto i: graph) {
            if(d[i->y] > d[i->x] + i->w){
                x = 1;
                d[i->y] = d[i->x] + i->w;
            }
        }
        if(x == -1) break;
    }

    for(int i = 0; i < Q; i++) {

        std::cin >> e;
        e--;

        if(d[e] == INT64_MAX) {
            std::cout << -1 << '\n';
        } else {
            std::cout << d[e] << '\n';
        }
    }


    return 0;
}
