#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n {0}, tmp{0};
	cin >> n;
	vector<int> v;
	v.reserve(n);

	for(int i=0; i<n; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	vector<int> result;
	for(int i=0; i<n; ++i)
	{
		auto it = find(v.begin()+i+1, v.end(), v[i]);
		if(it != v.end())
			result.push_back(distance(v.begin()+i, it));
	}

	if(result.empty())
		cout << "-1";
	else
		cout << *min_element(result.begin(), result.end());

    return 0;
}
