#include <iostream>
#include <vector>

std::vector<std::vector<int>> input;
std::vector<std::vector<bool>> visited;
int counter = 0;


void dfs(int y, int x) {
	visited[y][x] = true;
	if (x > 0 && input[y][x - 1] == '.' && !visited[y][x - 1]) dfs(y, x - 1);
	if (x < input[y].size() - 1 && input[y][x + 1] == '.' && !visited[y][x + 1]) dfs(y, x + 1);
	if (y > 0 && input[y - 1][x] == '.' && !visited[y - 1][x]) dfs(y - 1, x);
	if (y < input.size() - 1 && input[y + 1][x] == '.' && !visited[y + 1][x]) dfs(y + 1, x);
}

int main() {
	int n, m;
	std::cin >> n >> m;

	char buff;

	for (int i = 0; i < n; i++) {
		input.push_back({});
		visited.push_back({});
		for (int j = 0; j < m; j++) {
			std::cin >> buff;
			visited[i].push_back(false);
			input[i].push_back(buff);
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (input[y][x] == '.' && !visited[y][x]) {
				dfs(y, x);
				counter++;
			}
		}
	}

	std::cout << counter;
}
