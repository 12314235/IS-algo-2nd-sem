#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;
std::vector<int> stack;

void TopSort(int curr) {
    visited[curr] = true;

    for(int i : graph[curr]) {
        if(!visited[i]) {
            TopSort(i);
        }
    }

    stack.push_back(curr);
};

int main() {
    int n, m;
    std::cin >> n >> m;

    graph.assign(n, {});
    visited.assign(n, false);

    int curr, to;

    for (int i = 0; i < m; i++) {
        std::cin >> curr >> to;
        graph[curr - 1].push_back(to - 1);
    }


    for(int i = 0; i < n; i++) {
        if(!visited[i]) TopSort(i);
    }

    std::vector<int> new_graph;

    new_graph.assign(n, 0);

    int counter = 1;

    for(int i = stack.size() - 1; i >= 0; i--){
        new_graph[stack[i]] = counter;
        counter++;
    }

    for(auto i : new_graph){
        std::cout << i << ' ';
    }
}
