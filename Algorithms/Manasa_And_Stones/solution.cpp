#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, a, b;
    cin >> t;

    for(int i=0; i<t; ++i) {
    	cin >> n;
    	cin >> a;
    	cin >> b;

    	int diff = abs(a-b);
    	long result = a<b ? a*(n-1) : b*(n-1);
    	if(diff == 0)
    		cout << result;
    	else {
    		for(int i=0; i<n; ++i) {
				cout << result << " ";
				result += diff;
			}
    	}

    	cout << endl;
    }

	return 0;
}
