#include <iostream>
#include <vector>

#define int long long

std::vector<std::pair<int, std::pair<int, int>>> graph;
std::vector<std::pair<int, std::pair<int, int>>> graph2;

int* p;
int* rg;

void init(int count) {
    for (int i = 0; i < count; ++i) {
        p[i] = i;
        rg[i] = 0;
    }
}

int get(int a) {
    if (p[a] == a) return a;
    return (p[a] = get(p[a]));
}

void join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (rg[a] > rg[b]) std::swap(a, b);
        rg[b] += rg[a];
        p[a] = b;
    }
}

signed main() {
    int N, M, w;

    std::cin >> N >> M;

    p = new int[N + 1];
    rg = new int[N + 1];

    init(N + 1);

    int x, y, c;

    for(int i = 0; i < M; i++) {
        std::cin >> x >> y >> c;
        graph.emplace_back(c, std::make_pair(x, y));
    }

    std::sort(graph.begin(), graph.end());

    int res = 0;

    for(auto i : graph) {
        if(get(i.second.first) != get(i.second.second)) {
            join(i.second.first, i.second.second);
            res += i.first;
        }
        else {
            graph2.emplace_back(i);
        }
    }

    std::cout << res << ' ';

    res = graph2[0].first;
     init(N + 1);

    join(graph2[0].second.first, graph2[0].second.second);

    for(auto i : graph) {
        if(get(i.second.first) != get(i.second.second)) {
            join(i.second.first, i.second.second);
            res += i.first;
        }
    }

    std::cout << res;

    return 0;
}
