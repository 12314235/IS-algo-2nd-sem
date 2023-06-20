#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> is_safe_room;
std::vector<std::pair<bool, int>> visited;
std::vector<bool> is_safe_component;
int counter = 0;

void dfs(int current) {
    visited[current].first = true;
    visited[current].second = counter;
    is_safe_component.back() = is_safe_room[current] & is_safe_component.back();

    for(auto i : graph[current]) {
        if(!visited[i].first) {
            dfs(i);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    graph.assign(n, {});
    visited.assign(n, std::make_pair(false, 0));
    is_safe_room.assign(n, false);

    int curr, to;

    for (int i = 0; i < m; i++) {
        std::cin >> curr >> to;
        graph[curr - 1].push_back(to - 1);
        graph[to - 1].push_back(curr - 1);
    }

    for(int i = 0; i < n; i++) {
        std::cin >> curr;
        is_safe_room[i] = (curr == 0);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i].first){
            counter++;
            is_safe_component.emplace_back(true);
            dfs(i);
        }
    }

    std::cout << counter << '\n';
    for(auto i : visited){
        std::cout << i.second << ' ';
    }
    std::cout << '\n';

    for(auto i : is_safe_component){
        std::cout << (i ? 0 : 1) << ' ';
    }
}
