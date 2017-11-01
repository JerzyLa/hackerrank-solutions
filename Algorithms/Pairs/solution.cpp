#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long n, k;
	cin >> n >> k;
	set<long> s;

	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		s.insert(move(tmp));
	}

	auto it1 = s.begin();
	auto it2 = s.begin();
	long result{0};

	while(it2 != s.end()) {
		while(it2 != s.end() && *it2 < k+*it1) {
			++it2;
		}
		if(it2 != s.end() && *it2 == k+*it1)
			++result;

		++it1;
	}

	cout << result << endl;

    return 0;
}
