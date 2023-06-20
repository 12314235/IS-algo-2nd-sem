#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph;
std::queue<int> queue;
char* colors;
int* distant;
int N, F;
int res = 0;
bool find = false;

void min_path(int vertex) {
	queue.push(vertex);
	distant[vertex] = 1;
	while (queue.size() != 0) {
		int current = queue.front();
		queue.pop();
		for (int i : graph[current]) {
			if (distant[i] == 0) {
				distant[i] = distant[current] + 1;
				queue.push(i);
			}
		}
	}
}

int main() {
	int M;

	std::cin >> N >> M;

	if (N <= 2 || M <= 2) {
		std::cout << "NO";
		return 0;
	}

	colors = new char[N + 1];
	distant = new int[N + 1];

	for (int i = 0; i < N + 1; i++) {
		graph.push_back({});
		colors[i] = 'W';
		distant[i] = 0;
	}

	int x, y;

	for (int i = 0; i < M; i++) {
		std::cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int S;

	std::cin >> S >> F;

	min_path(S);

	std::cout << distant[F] - 1;
}
