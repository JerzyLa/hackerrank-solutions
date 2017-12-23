#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long combination(unsigned long n)
{
	if(n==1)
		return 1;

	if(n==2)
		return 3;

	return ((combination(n-1))*2+1) % 100000;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned tests, tmp;
    cin >> tests;

    vector<unsigned long> testCases;
    for(int i=0; i<tests; ++i)
    {
        cin >> tmp;
        testCases.push_back(tmp);
    }

    for(const auto& el : testCases)
    	cout << combination(el) << endl;

    return 0;
}
