#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n{0};
	cin >> n;
	vector<int> tab;
	tab.resize(n);

	for(int i=0; i<n; ++i) {
		int tmp;
		cin >> tmp;
		tab[i] = tmp;
	}

	sort(begin(tab), end(tab));

	int minDifference = numeric_limits<int>::max();
	vector<int> result;

	for(int i=1; i<n; ++i) {
		int difference = abs(tab[i]-tab[i-1]);
		if(difference == minDifference) {
			result.insert(end(result), {tab[i-1], tab[i]});
		}
		else if(difference < minDifference) {
			minDifference = difference;
			result.clear();
			result.insert(end(result), {tab[i-1], tab[i]});
		}
	}

	copy(begin(result), end(result), ostream_iterator<int>(cout, " "));
    return 0;
}
