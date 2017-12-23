#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n{0}, d{0}, tmp{0};
	cin >> n >> d;
	vector<int> v;
	v.reserve(n);

	for(int i=0; i<n; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	int result{0};
	for(auto el: v)
	{
		auto it = find(v.begin(), v.end(), d+el);
		if(it != v.end())
		{
			it = find(v.begin(), v.end(), 2*d+el);
			if(it != v.end())
				++result;
		}
	}

	cout << result;

    return 0;
}
