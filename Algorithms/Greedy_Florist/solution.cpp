#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n{0}, k{0};
	cin >> n >> k;
	vector<int> c;
	c.reserve(n);

	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		c.push_back(tmp);
	}

	sort(begin(c), end(c));
	int num = n/k;
	int result{0};

	int i=0;
	for(; i<n%k; ++i)
		result += c[i] * (num+1);

	for(int x=0; i<n; ++i, ++x) {
		if(x == k) {
			num -= 1;
			x = 0;
		}
		result += c[i] * (num);
	}

	cout << result << endl;

    return 0;
}
