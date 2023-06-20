#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;

	std::vector<std::string> output;

	if (N == 0) {
		return 0;
	}

	output.push_back("0");
	output.push_back("1");

	for (int i = 1; i < N; i++) {
		for (int j = output.size() - 1; j >= 0; j--) {
			output.push_back("1" + output[j]);
		}
		for (int j = 0; j < output.size() / 2; j++) {
			output[j].insert(0, "0");
		}
	}

	for (int i = 0; i < output.size(); i++) {
		std::cout << output[i] << '\n';
	}
}
