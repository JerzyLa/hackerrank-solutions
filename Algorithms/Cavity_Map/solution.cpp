#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	char grid[n][n];

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> grid[i][j];

	for(int i=1; i<n-1; ++i) {
		for(int j=1; j<n-1; ++j) {
			if(grid[i][j] > grid[i+1][j] && grid[i][j] > grid[i][j+1]
				&& grid[i][j] > grid[i-1][j] && grid[i][j] > grid[i][j-1])
					grid[i][j] = 'X';
		}
	}

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cout << grid[i][j];
		}
		cout << endl;
	}

	return 0;
}
