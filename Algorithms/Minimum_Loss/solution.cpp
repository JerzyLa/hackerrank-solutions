#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/// 1. insert new element in sorted set
/// 2. check the next greater element and calculate the difference
/// 3. check whether difference is smaller than actual.

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long result = numeric_limits<long>::max();
	long n{0}, p{0};
	cin >> n;
	set<long> container;

	for(long i=0; i<n; ++i) {
		cin >> p;
		auto tmp = container.insert(p);
		auto it = ++tmp.first;
		if(it != container.end() && *it - p < result)
			result = *it - p;
	}

	cout << result << endl;

    return 0;
}
