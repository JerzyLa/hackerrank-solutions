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
	vector<int> vec(n);
	for(auto& el : vec)
		cin >> el;

	vector<int> sorted(vec);
	sort(sorted.begin(), sorted.end());

	auto pair = make_pair(-1,-1);
	int wrong{0};
	bool reverse = true;
	for(int i=0; i<n; ++i) {
		if(vec[i] != sorted[i])
		{
			if(pair.first == -1)
				pair.first = i;
			else {
				pair.second = i;
				if(vec[i] > vec[i-1])
					reverse = false;
			}
			++wrong;
		}
	}

	if(pair.first == -1)	// sorted
		cout << "yes";
	else if(wrong == 2)		// swap
		cout << "yes\n" << "swap " << pair.first+1 << " " << pair.second+1 << endl;
	else if(reverse)		// reversed
		cout << "yes\n" << "reverse " << pair.first+1 << " " << pair.second+1 << endl;
	else
		cout << "no";

    return 0;
}
