#include <iostream>
#include <vector>
#include <queue>

struct position {
	int x;
	int y;
	int z;
};

int E;

bool visited[101][101][101];
std::queue<position> queue;
int distant[101][101][101];

position start;
position finish;
position current;

void min_distant(const position& vertex) {
	queue.push(vertex);
	distant[vertex.x][vertex.y][vertex.z] = 1;
	while (!queue.empty()) {
		current = queue.front();
		visited[current.x][current.y][current.z] = true;
		queue.pop();
		if (distant[current.x][current.y][current.z] > E) continue;;
		if (current.x < 100 && !visited[current.x + 1][current.y][current.z]) {
			queue.push({ current.x + 1, current.y, current.z });
			visited[current.x + 1][current.y][current.z] = true;
			distant[current.x + 1][current.y][current.z] = distant[current.x][current.y][current.z] + 1;
		}
		if (current.y < 100 && !visited[current.x][current.y + 1][current.z]) {
			queue.push({ current.x, current.y + 1, current.z });
			visited[current.x][current.y + 1][current.z] = true;
			distant[current.x][current.y + 1][current.z] = distant[current.x][current.y][current.z] + 1;
		}
		if (current.z < 100 && !visited[current.x][current.y][current.z + 1]) {
			queue.push({ current.x, current.y, current.z + 1 });
			visited[current.x][current.y][current.z + 1] = true;
			distant[current.x][current.y][current.z + 1] = distant[current.x][current.y][current.z] + 1;
		}
		if (current.x > 0 && !visited[current.x - 1][current.y][current.z]) {
			queue.push({ current.x - 1, current.y, current.z });
			visited[current.x - 1][current.y][current.z] = true;
			distant[current.x - 1][current.y][current.z] = distant[current.x][current.y][current.z] + 1;
		}
		if (current.y > 0 && !visited[current.x][current.y - 1][current.z]) {
			queue.push({ current.x, current.y - 1, current.z });
			distant[current.x][current.y - 1][current.z] = distant[current.x][current.y][current.z] + 1;
		}
		if (current.z > 0 && !visited[current.x][current.y][current.z - 1]) {
			queue.push({ current.x, current.y, current.z - 1 });
			visited[current.x][current.y][current.z - 1] = true;
			distant[current.x][current.y][current.z - 1] = distant[current.x][current.y][current.z] + 1;
		}
	}
}

int main() {
	int K;

	std::cin >> K >> E;

	std::cin >> start.x >> start.y >> start.z;
	std::cin >> finish.x >> finish.y >> finish.z;

	start.x;
	start.y;
	start.z;
	finish.x;
	finish.y;
	finish.z;

	for (int i = 0; i < 101; i++) {
		for (int y = 0; y < 101; y++) {
			for (int z = 0; z < 101; z++) {
				visited[i][y][z] = false;
				distant[i][y][z] = 0;
			}
		}
	}

	int x, y, z, h;

	for (int i = 0; i < K; i++) {
		std::cin >> x >> y >> z >> h;
		for (int k = z; k < std::min(101, z + h); k++) {
			visited[x][y][k] = true;
		}
	}

	min_distant(start);

	std::cout << distant[finish.x][finish.y][finish.z] - 1;
}
