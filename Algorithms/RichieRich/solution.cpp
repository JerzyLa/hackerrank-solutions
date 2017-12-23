#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n{0}, k{0};
	string str;
	cin >> n >> k >> str;

	vector<int> pos;

	/// create palindrome with the smallest number of changes
	for(int i=0; i<n/2; ++i)
	{
		if(str[i] != str[n-i-1])
		{
			if(str[i] > str[n-i-1])
				str[n-i-1] = str[i];
			else
				str[i] = str[n-i-1];

			pos.push_back(i);
		}
	}

    /// add apropriate amount of '9'
	if(pos.size() == k)
		cout << str;
	else if(pos.size() > k)
		cout << "-1";
	else if (pos.size() < k)
	{
		int tmp{0};
		for(int i=0; i<n/2+1; ++i)
		{
			if(str[i] != '9')
			{
				if(find(pos.begin(), pos.end(), i) != pos.end())
				{
					str[i] = '9';
					str[n-i-1] = '9';
					++tmp;
				}
				else if(tmp + 2 + pos.size() <= k)
				{
					str[i] = '9';
					str[n-i-1] = '9';
					tmp +=2;
				}
				else if(i == n-i-1)
				{
					str[i] = '9';
					++tmp;
				}

				if(tmp + pos.size() == k)
					break;
			}
		}

		cout << str;
	}

    return 0;
}
