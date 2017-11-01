#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/// solution based on "Count inversions in an array | Set 3 (Using BIT)" on GeekForGeeks.org
/// http://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/

/// BITree struct solves problem of sum n elements from array with logarithm complexity (logn).
int getSumOfNElements(const vector<int>& BITree, size_t index) {
	int sum{0};

	while(index > 0) {
		sum += BITree[index];
		index -= index & (-index);
	}

	return sum;
}

void update(vector<int>& BITree, size_t index, int val) {
	while(index < BITree.size()) {
		BITree[index] += val;

		index += index & (-index);
	}
}

/// construct BITree has complexity (nlogn), but sum execution is lonn
vector<int> constructBITree(const vector<int>& arr) {
	/// initialize BITree with zeros
	vector<int> BITree(arr.size()+1, 0);

	/// actual BITree with update
	for(size_t i=0; i<arr.size(); ++i)
		update(BITree, i+1, arr[i]);

	return BITree;
}

long getInvCount(const vector<int> arr) {
	long invcount{0};
	int maxElement =  *max_element(arr.begin(), arr.end());

	vector<int> BITree(maxElement+1, 0);
	for(int i=arr.size()-1; i>=0; --i) {
		invcount += getSumOfNElements(BITree, arr[i]-1);
		update(BITree, arr[i], 1);
	}

	return invcount;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int t{0};
	cin >> t;
	for(int i=0; i<t; ++i) {
		int n{0}, c{0};
		cin >> n;
		vector<int> vec;
		vec.reserve(n);

		for(auto j=0; j<n; ++j) {
			cin >> c;
			vec.push_back(c);
		}

		cout << getInvCount(vec) << endl;
	}

    return 0;
}
