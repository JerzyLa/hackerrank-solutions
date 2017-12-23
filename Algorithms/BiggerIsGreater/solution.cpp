#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename Iter>
bool my_next_permutation(Iter b, Iter e)
{
	if(b==e)
		return false;

	auto it = (e-1);
	while(b!=it && *(it-1) >= *it) --it;

	if(b==it)
		return false;

	--it;
	auto it2 = (e-1);
	while(*it >= *it2) --it2;
	swap(*it, *it2);
	reverse(it+1, e);
	return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	unsigned cases{0};
	cin >> cases;

	vector<string> v;
	string tmp;
	for(unsigned i=0; i<cases; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	for(auto& el : v)
	{
        bool result = my_next_permutation(begin(el), end(el));

		if(result)
			cout << el << endl;
		else
			cout << "no answer\n";
	}

    return 0;
}
