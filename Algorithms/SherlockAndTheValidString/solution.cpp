#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool equalOccurencs(const vector<int>& v)
{
	auto avg = *find_if(v.begin(), v.end(), [](auto& el){ return el!=0; });
	for(const auto& el : v)
		if(el != 0 && el != avg)
			return false;

	return true;
}

bool isOk(vector<int>& v)
{
	if(equal(v.begin()+1, v.end(), v.begin()))
		return true;

	for(int i=0; i<v.size(); ++i)
	{
		--v[i];
		if(equalOccurencs(v))
			return true;
		++v[i];

	}

	return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string str;
	cin >> str;

	map<char, int> occures;
	vector<int> v;
	for_each(begin(str), end(str), [&occures](char c){ ++occures[c]; });
	transform(begin(occures), end(occures), back_inserter(v), [](auto& el){ return el.second;});

	if(isOk(v))
		cout << "YES";
	else
		cout << "NO";

    return 0;
}
