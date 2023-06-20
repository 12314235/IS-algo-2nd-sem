#include <iostream>
#include <vector>

int n;

int* p;
int* rg;

void init(int count) {
    for (int i = 0; i < count; ++i) {
        p[i] = i;
        rg[i] = 0;
    }
}

int get(int a) {
    if (p[a] == a) return a;
    return (p[a] = get(p[a]));
}

void join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (rg[a] > rg[b]) std::swap(a, b);
        rg[b] += rg[a];
        p[a] = b;
    }
}

struct Question {
    char operation;
    int a;
    int b;
};

std::vector<std::vector<int>> graph;
std::vector<Question> questions;
std::vector<std::string> ans;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int m, q;

    std::cin >> n >> m >> q;

    p = new int[n];
    rg = new int[n];

    int a, b;

    graph.resize(n);

    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    char command;

    for (int j = 0; j < q; j++) {
        std::cin >> command >> a >> b;

        questions.push_back({command, a - 1, b - 1});

        if (command == '-') {
            for(int i = 0; i < graph[a - 1].size(); i++) {
                if(graph[a - 1][i] == b - 1) {
                    graph[a - 1].erase(graph[a - 1].begin() + i);
                }
            }
            for(int i = 0; i < graph[b - 1].size(); i++) {
                if(graph[b - 1][i] == a - 1) {
                    graph[b - 1].erase(graph[b - 1].begin() + i);
                }
            }
        }

    }

    init(n);

    for (int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            join(i, graph[i][j]);
        }
    }

    for (int i = questions.size() - 1; i >= 0; i--) {
        switch (questions[i].operation) {
            case '?':
                ans.emplace_back(get(questions[i].a) == get(questions[i].b) ? "YES\n" : "NO\n");
                break;
            case '-':
                join(questions[i].a, questions[i].b);
                break;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        std::cout << ans[i];
    }
}
