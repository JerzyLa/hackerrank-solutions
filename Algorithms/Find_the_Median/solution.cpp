#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n{0};
	cin >> n;
	vector<int> vec;
	vec.reserve(n);

	for(int i=0; i<n; ++i) {
		int tmp{0};
		cin >> tmp;
		vec.emplace_back(tmp);
	}

	sort(begin(vec), end(vec));
	cout << vec[vec.size() / 2];

    return 0;
}
