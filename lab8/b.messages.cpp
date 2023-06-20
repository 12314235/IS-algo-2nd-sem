#include <iostream>
#include <vector>

bool is_digital(char symb) {
	return symb >= '0' && symb <= '9';
}

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<std::pair<char, int>> message_masha;

	char buff;
	char symb;
	int count = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> buff;
		if (!is_digital(buff)) {
			if (count == 0) {
				symb = buff;
			}
			else {
				message_masha.push_back(std::make_pair(symb, count));
				symb = buff;
				count = 0;
			}
		}
		else if (is_digital(buff)) {
			count = count * 10 + (buff - '0');
			if (i == n - 1) {
				message_masha.push_back(std::make_pair(symb, count));
			}
		}
	}

	std::vector<std::pair<char, int>> message_sasha;

	count = 0;


	for (int i = 0; i < m; i++) {
		std::cin >> buff;
		if (!is_digital(buff)) {
			if (count == 0) {
				symb = buff;
			}
			else {
				message_sasha.push_back(std::make_pair(symb, count));
				symb = buff;
				count = 0;
			}
		}
		else if (is_digital(buff)) {
			count = count * 10 + (buff - '0');
			if (i == m - 1) {
				message_sasha.push_back(std::make_pair(symb, count));
			}
		}
	}

	int masha_it = 0;
	int sasha_it = 0;
	int difference = 0;

	if (message_masha.size() == 0 || message_sasha.size() == 0) {
		std::cout << (k > 0 ? "Yes" : "No");
	}
	else {
		while (message_masha.back().second != 0 || message_sasha.back().second != 0) {
			if (message_masha[masha_it].second > message_sasha[sasha_it].second) {
				if (message_masha[masha_it].first != message_sasha[sasha_it].first) {
					difference += message_sasha[sasha_it].second;
				}
				message_masha[masha_it].second -= message_sasha[sasha_it].second;
				message_sasha[sasha_it].second = 0;
				if (sasha_it < message_sasha.size() - 1) sasha_it++;
			}
			else if (message_masha[masha_it].second < message_sasha[sasha_it].second) {
				if (message_masha[masha_it].first != message_sasha[sasha_it].first) {
					difference += message_masha[masha_it].second;
				}
				message_sasha[sasha_it].second -= message_masha[masha_it].second;
				message_masha[masha_it].second = 0;
				if (masha_it < message_masha.size() - 1) masha_it++;
			}
			else {
				if (message_masha[masha_it].first != message_sasha[sasha_it].first) {
					difference += message_sasha[sasha_it].second;
				}
				message_masha[masha_it].second = 0;
				message_sasha[sasha_it].second = 0;
				if (masha_it < message_masha.size() - 1) masha_it++;
				if (sasha_it < message_sasha.size() - 1) sasha_it++;
			}
		}
		std::cout << (difference < k ? "Yes" : "No");
	}
}
