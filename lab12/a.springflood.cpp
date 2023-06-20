#include <iostream>
#include <vector>
#include <queue>

#define int long long

std::vector<std::vector<std::pair<int, int>>> graph;

std::vector<int> queue;
std::vector<int> colors;

int extract_min() {
    int res = INT64_MAX;
    int ind = 0;

    for(int i = 0; i < queue.size(); i++) {
        if(res > queue[i] && colors[i] == 0) {
            res = queue[i];
            ind = i;
        }
    }

    colors[ind] = 1;
    return ind;
}

signed main() {
    int N, M, w;

    std::cin >> N >> M;


    std::vector<int> parents;

    for(int i = 0; i < N; i++) {
        queue.push_back(INT64_MAX);
        colors.push_back(0);
        graph.push_back({});
        parents.push_back(-1);
    }

    int x, y, z;

    for(int i = 0; i < M; i++) {
        std::cin >> x >> y >> z;
        x--;
        y--;
        graph[x].emplace_back(std::make_pair(y, z));
        graph[y].emplace_back(std::make_pair(x, z));
    }

    queue[0] = 0;
    for(int i = 0; i < N - 1; i++) {
        int v = extract_min();
        for(auto i : graph[v]) {
            if(queue[i.first] > i.second && colors[i.first] != 1) {
                parents[i.first] = v;
                queue[i.first] = i.second;
            }
        }
    }

    int res = 0;

    for(int i = 1; i < N; i++) {
        for(auto j : graph[i]) {
            if(j.first == parents[i]) {
                res += j.second;
                break;
            }
        }
    }

    std::cout << res;

    return 0;
}
