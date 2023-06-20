#include <iostream>
#include <vector>

//#define int long
#define SIZE 10133
#define SIZE_GROUP 271


std::vector<std::vector<std::pair<int, int>>> table(SIZE, std::vector<std::pair<int, int>>(SIZE_GROUP, std::make_pair(-2, 0)));

int h1(int k) {
    return k % SIZE;
}

int h(int k) {
    return k % SIZE_GROUP;
}

int g(int k) {
    return 1 + k % (SIZE_GROUP - 1);
}

int H(int k, int i) {
    return (h(k) + i * g(k)) % SIZE_GROUP;
}

void add(int group, int isu, int points) {
    group = h1(group);
    for(int i = 0; i < SIZE_GROUP; i++) {
        if(table[group][H(isu, i)].first == -2 || table[group][H(isu, i)].first == -1) {
            table[group][H(isu, i)] = std::make_pair(isu, points);
            break;
        }
    }
}

void delete_s(int group, int isu) {
    group = h1(group);
    for(int i = 0; i < SIZE_GROUP && table[group][H(isu, i)].first != -2; i++) {
        if(table[group][H(isu, i)].first == isu) {
            table[group][H(isu, i)] = std::make_pair(-1, 0);
            break;
        }
    }
}

int average_point(int group) {
    group = h1(group);
    int counter = 0;
    int sum = 0;
    for(auto i : table[group]) {
        if(i.first >= 0) {
            counter++;
            sum += i.second;
        }
    }

    return sum / counter;
}

int max_point(int group) {
    group = h1(group);
    int max = 0;
    int counter = 0;
    for(auto i : table[group]) {
        max = std::max(max, i.second);
    }

    return max;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int M, Q;

    std::cin >> M >> Q;

    char command;
    int group, isu, points;

    for(int  i = 0; i < Q; i++) {
        std::cin >> command;
        switch(command) {
            case 'a':
                std::cin >> group;
                std::cout << average_point(group) << '\n';
                break;
            case '-':
                std::cin >> group >> isu;
                delete_s(group, isu);
                break;
            case '+':
                std::cin >> group >> isu >> points;
                add(group, isu, points);
                break;
            case 'm':
                std::cin >> group;
                std::cout << max_point(group) << '\n';
                break;
        }
    }

    return 0;
}
