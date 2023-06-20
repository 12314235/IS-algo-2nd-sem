#include <iostream>
#include <string>
#include <vector>

int main() {
	int N;
	std::cin >> N;

	std::string input;

	std::vector<bool> coded;
	std::vector<int> control_bits;
	std::vector<bool> coded_fixed;

	while(std::cin >> input) {
		coded.clear();
		coded_fixed.clear();
		control_bits.clear();
		//std::cin >> input;
		for (char j : input) {
			coded.push_back(j == '1');
			coded_fixed.push_back(j == '1');
		}

		for (int j = 1; j <= input.size(); j *= 2) {
			control_bits.push_back(j - 1);
			coded_fixed[j - 1] = 0;
		}

		int sum = 0;
		int counter = 0;

		for (int j : control_bits) {
			sum = 0;
			for (int k = j; k < coded_fixed.size(); k += (j + 1) * 2) {
				counter = k;
				while (counter < k + (j + 1) && counter < coded_fixed.size()) {
					sum += coded_fixed[counter];
					counter++;
				}
			}

			coded_fixed[j] = sum % 2;
		}

		int error_bit_index = 0;

		for (int j : control_bits) {
			error_bit_index += coded_fixed[j] != coded[j] ? j + 1 : 0;
		}

		if (error_bit_index != 0) {
			coded_fixed[error_bit_index - 1] = !coded_fixed[error_bit_index - 1];
		}

		counter = 0;

		for (int j = 0; j < coded_fixed.size(); j++) {
			if (j == control_bits[counter]) {
				if (counter + 1 < control_bits.size()) counter++;
			}
			else {
				std::cout << coded_fixed[j];
			}
		}

		std::cout << '\n';

	}
}
