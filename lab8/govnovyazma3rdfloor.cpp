#include <iostream>
#include <vector>

int N;

struct Int_Node {
	int value;
	int left;
	int parent;
	int right;

	Int_Node(int val, int l, int r) {
		value = val;
		left = l;
		right = r;
	}
};

class Tree_Numbers {
private:
	std::vector<Int_Node*> tree;
	int counter = 1;

public:

	int head = 1;

	std::vector<int> bypass;

	Tree_Numbers() {
		this->tree.push_back(nullptr);
	}

	void add(int x) {
		Int_Node* new_node = new Int_Node(x, -1, -1);
		if (counter % 2 == 0) {
			new_node->parent = counter / 2;
		}
		else if (counter == 1){
			new_node->parent = -1;
		}
		else {
			new_node->parent = (counter - 1) / 2;
		}
		counter++;

		tree.push_back(new_node);

		int ind = tree.size() - 1;

		if (ind % 2 == 0 && ind > 1) {
			tree[ind / 2]->left = ind;
		}
		else if (ind % 2 != 0 && ind > 1) {
			tree[(ind - 1) / 2]->right = ind;
		}
	}

	void change(int v) {

		if (v > N || v <= 0) {
			return;
		}
		if (v == head) {
			return;
		}

		int p = tree[v]->parent;
		if (p == head) head = v;
		int pp = p > 0 ? tree[p]->parent : -1;
		int vl = tree[v]->left;
		int vr = tree[v]->right;

		if (p != 0) {
			if (pp <= 0) {
				tree[v]->parent = -1;
			}
			else {
				if (tree[pp]->left == p) {
					tree[pp]->left = v;
					tree[v]->parent = pp;
				}
				else {
					tree[pp]->right = v;
					tree[v]->parent = pp;
				}
			}

			if (tree[p]->left == v) {
				tree[v]->left = p;
				tree[p]->parent = v;
				tree[p]->left = vl;
				if (vl > 0) tree[vl]->parent = p;
			}
			else {
				tree[v]->right = p;
				tree[p]->parent = v;
				tree[p]->right = vr;
				if (vr > 0) tree[vr]->parent = p;
			}
		}

	}

	void post_order_bypass(int current) {
		if (tree[current]->left != -1) {
			post_order_bypass(tree[current]->left);
		}
		if (tree[current]->right != -1) {
			post_order_bypass(tree[current]->right);
		}
		this->bypass.push_back(tree[current]->value);
	}
};

struct Literal_Node {
	char value;
	int left;
	int right;
	int parent;

	Literal_Node(char val, int left, int right) {
		value = val;
		this->left = left;
		this->right = right;
	}
};

class Tree_Literals {
private:
	std::vector<Literal_Node*> tree;
	int counter = 1;

public:

	int head = 1;

	std::vector<char> bypass = {};

	Tree_Literals() {
		this->tree.push_back(nullptr);
	}

	void add(char x) {
		Literal_Node* new_node = new Literal_Node(x, -1, -1);
		if (counter % 2 == 0) {
			new_node->parent = counter / 2;
		}
		else if (counter == 1) {
			new_node->parent = -1;
		}
		else {
			new_node->parent = (counter - 1) / 2;
		}
		counter++;

		tree.push_back(new_node);

		int ind = tree.size() - 1;

		if (ind % 2 == 0 && ind > 1) {
			tree[ind / 2]->left = ind;
		}
		else if (ind % 2 != 0 && ind > 1) {
			tree[(ind - 1) / 2]->right = ind;
		}
	}

	void change(int v) {

		if (v > N || v <= 0) {
			return;
		}
		if (v == head) {
			return;
		}

		int p = tree[v]->parent;
		if (p == head) head = v;
		int pp = p > 0 ? tree[p]->parent : -1;
		int vl = tree[v]->left;
		int vr = tree[v]->right;

		if (p != 0) {
			if (pp <= 0) {
				tree[v]->parent = -1;
			}
			else {
				if (tree[pp]->left == p) {
					tree[pp]->left = v;
					tree[v]->parent = pp;
				}
				else {
					tree[pp]->right = v;
					tree[v]->parent = pp;
				}
			}

			if (tree[p]->left == v) {
				tree[v]->left = p;
				tree[p]->parent = v;
				tree[p]->left = vl;
				if (vl > 0) tree[vl]->parent = p;
			}
			else {
				tree[v]->right = p;
				tree[p]->parent = v;
				tree[p]->right = vr;
				if (vr > 0) tree[vr]->parent = p;
			}
		}

	}


	void post_order_bypass(int current) {
		if (tree[current]->left != -1) {
			post_order_bypass(tree[current]->left);
		}
		if (tree[current]->right != -1) {
			post_order_bypass(tree[current]->right);
		}
		this->bypass.push_back(tree[current]->value);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int Q1;
	std::cin >> N >> Q1;

	Tree_Numbers numbers;
	int x;

	for (int i = 0; i < N; i++) {
		std::cin >> x;
		numbers.add(x);
	}

	for (int i = 0; i < Q1; i++) {
		std::cin >> x;
		numbers.change(x);
	}

	int Q2;

	std::cin >> N >> Q2;

	Tree_Literals literals;
	char y;

	for (int i = 0; i < N; i++) {
		std::cin >> y;
		literals.add(y);
	}

	for (int i = 0; i < Q2; i++) {
		std::cin >> x;
		literals.change(x);
	}

	numbers.post_order_bypass(numbers.head == 0 ? 1 : numbers.head);
	literals.post_order_bypass(literals.head == 0 ? 1 : literals.head);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < numbers.bypass[i]; j++) {
			std::cout << literals.bypass[i];
		}
	}
}
