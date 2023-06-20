#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
char* colors;
std::vector<int> path;

void dfs(int vertex) {
	colors[vertex] = 'B';
	for (int i : graph[vertex]) {
		if (colors[i] == 'W') {
			dfs(i);
		}
	}
	path.push_back(vertex);
}

int main() {
	int n, m;
	std::cin >> n >> m;
	
	colors = new char[n];

	for (int i = 0; i < n; i++) {
		graph.push_back({});
		colors[i] = 'W';
	}

	int x, y;

	for (int i = 0; i < m; i++) {
		std::cin >> x >> y;

		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}

	dfs(1);

	for (int i = 0; i < n; i++) {
		if (colors[i] != 'B') {
			std::cout << "NO";
			return 0;
		}
	}

	int counter = 0;

	for (int i = 0; i < graph.size(); i++) {
		if (graph[i].size() < 2) {
			counter++;
		}
		if (counter > 2) {
			std::cout << "NO";
			return 0;
		}
	}

	std::cout << "YES";
}
