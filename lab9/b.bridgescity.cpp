#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
char* colors;
int N;
bool res = false;

void dfs(int vertex, int parent) {
	colors[vertex] = 'G';
	for (int i = 0; i < graph[vertex].size(); i++) {
		if (res) {
			return;
		}
		if (colors[graph[vertex][i]] == 'W') {
			dfs(graph[vertex][i], vertex);
		}
		if (colors[graph[vertex][i]] == 'G' && graph[vertex][i] != parent && graph[vertex][i] != vertex) {
			res = true;
			return;
		}
	}
    
	colors[vertex] = 'B';
}

int main() {
	int M;

	std::cin >> N >> M;

	if (N <= 2 || M <= 2) {
		std::cout << "NO";
		return 0;
	}

	colors = new char[N + 1];

	for (int i = 0; i < N + 1; i++) {
		graph.push_back({});
		colors[i] = 'W';
	}

	int x, y;

	for (int i = 0; i < M; i++) {
		std::cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i < N + 1; i++) {
		if (colors[i] == 'W') {
			dfs(i, -1);
		}
	}

	std::cout << (res ? "YES" : "NO");
}
