#include <iostream>
#include <vector>
#include <string>

#define SIZE 1200009
#define counter 117

std::vector<std::pair<std::string, std::vector<bool>>> a(SIZE, std::make_pair("", std::vector<bool>(3, false)));


int N;

std::pair<std::string, std::vector<bool>> bf;

int h1(const std::string& str) {
    int k = 0;
    for(auto i : str) {
        k += k * counter + i;
    }
    return (k) % (SIZE);
}

int h2(const std::string& str) {
    int k = 0;
    for(auto i : str) {
        k += k * counter + i;
    }
    return (k + 12345) % SIZE;
}

int find(const std::string& x) {
    if(a[h1(x)].first == x) {
        return h1(x);
    } else if(a[h2(x)].first == x) {
        return h2(x);
    } else {
        return -1;
    }
}

void insert(const std::string& x, int student) {
    int hash1 = h1(x);
    int hash2 = h2(x);

    if(find(x) != -1) {
        a[find(x)].second[student] = true;
    } else {
        bf = std::make_pair(x, std::vector<bool>{student == 0, student == 1, student == 2});
        if (a[hash1].first.empty()) {
            a[hash1] = bf;
        } else if (a[hash2].first.empty()) {
            a[hash2] = bf;
        } else {
            std::pair<std::string, std::vector<bool>> y = a[hash1];
            a[hash1] = bf;
            int prevh = hash1;
            while (!y.first.empty() && y != bf) {
                if (h1(y.first) == prevh) {
                    prevh = h2(y.first);
                    std::swap(a[prevh], y);
                } else {
                    prevh = h1(y.first);
                    std::swap(a[prevh], y);
                }
            }
            if(y == bf) {
                std::swap(y, a[hash2]);
                prevh = hash2;
                while (!y.first.empty() && y != bf) {
                    if (h1(y.first) == prevh) {
                        prevh = h2(y.first);
                        std::swap(a[prevh], y);
                    } else {
                        prevh = h1(y.first);
                        std::swap(a[prevh], y);
                    }
                }
            }
        }
    }
}



signed main() {
    std::cin >> N;

    std::vector<std::string> a_1(N);
    std::vector<std::string> a_2(N);

    std::string buff;

    for(int i = 0; i < N; i++) {
        std::cin >> a_1[i];
        insert(a_1[i], 0);
    }

    for(int i = 0; i < N; i++) {
        std::cin >> a_2[i];
        insert(a_2[i], 1);
    }

    for(int i = 0; i < N; i++) {
        std::cin >> buff;
        insert(buff, 2);
    }

    int score1 = 3 * N;
    int score2 = 3 * N;
    int score3 = 3 * N;

    bool f1, f2, f3;

    for (int i = 0; i < N; i++) {
        f1 = a[find(a_1[i])].second[1];
        f2 = a[find(a_1[i])].second[2];
        f3 = a[find(a_2[i])].second[2] && !a[find(a_2[i])].second[0];
        if (f1 && f2) {
            score1 -= 3;
            score2 -= 3;
            score3 -= 3;
        }
        else if (f1) {
            score1 -= 2;
            score2 -= 2;
        }
        else if (f2) {
            score1 -= 2;
            score3 -= 2;
        }
        if (f3) {
            score2 -= 2;
            score3 -= 2;
        }
    }

    std::cout << score1 << ' ' << score2 << ' ' << score3;

    return 0;
}
