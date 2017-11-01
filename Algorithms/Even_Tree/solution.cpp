#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Composite {
	Composite() {}
	bool isLeaf() const { return children.empty(); }
	int numOfChildren() {
		int num{0};
		for(const auto& el : children)
			num+=el->numOfChildren();
		num+=children.size();
		return num;
	}

	vector<Composite*> children;
};

int evenTree(Composite* root) {
	if(root->isLeaf())
		return 0;

	int result{0};
	for(int i=0; i<root->children.size(); ++i) {
		auto numOfChildren = root->children[i]->numOfChildren();
		if(numOfChildren%2 == 1)
			++result;
		result += evenTree(root->children[i]);
	}

	return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N, M, parent, child;
	cin >> N >> M;

	vector<Composite> tree(N);
	for(int i=0; i<M; ++i) {
		cin >> child;
		cin >> parent;
		tree[parent-1].children.push_back(&tree[child-1]);
	}

	cout << evenTree(&tree[0]) << endl;

    return 0;
}
