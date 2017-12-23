#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;

int lcs(string s1, string s2)
{
	vector<int> vec(s2.size(), 0);
	vector<int> prev(s2.size(), 0);

	for(int i=0; i<s1.size(); ++i)
	{
		for( int j=0; j<s2.size(); ++j)
		{
			if(j==0)
				vec[j] = (s1[i] == s2[j] ? 1:0);
			else if(s1[i] == s2[j])
				vec[j]=prev[j-1]+1;
			else
				vec[j] = max(vec[j-1], prev[j]);
		}
		prev=vec;
	}

	return vec.back();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string s1, s2;
	cin >> s1 >> s2;

	cout << lcs(s1, s2) << endl;

    return 0;
}
