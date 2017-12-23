#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int l{0}, t{0};
	cin >> l >> t;

	vector<int> width(l);
	for_each(begin(width), end(width), [](int& el){ cin >> el; });
	vector<pair<int, int>> cases(t);
	for_each(begin(cases), end(cases), [](auto& el){ cin >> el.first >> el.second; });

	for(const auto& el : cases)
		cout << *min_element(width.begin() + el.first, width.begin() + el.second + 1) << endl;

    return 0;
}
