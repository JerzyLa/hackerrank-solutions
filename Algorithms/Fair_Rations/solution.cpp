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
	vector<int> b(n);
	for(int i=0; i<n; ++i)
		cin >> b[i];

	int result{0};
	vector<int> odds;
	for(int i=0; i<n; ++i)
		if(b[i]%2)
			odds.push_back(i);

	if(odds.size()%2) {
		cout << "NO";
		return 0;
	}

	for(int i=0; i<odds.size(); i+=2)
		result += (odds[i+1] - odds[i] - 1) * 2 + 2;

	cout << result;

    return 0;
}
