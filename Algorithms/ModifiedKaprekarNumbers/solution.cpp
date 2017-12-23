#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

bool isKaprekar(long n)
{
	stringstream ss;
	ss << (n*n);
	int size = ss.str().size();
	int d = size/2;
	string num1 = ss.str().substr(d);
	string num2 = ss.str().substr(0, d);
	long a = stol(num1);
	long b{0};
	if(num2 != "")
		b = stol(num2);

	if(a+b == n)
		return true;
	else
		return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int b{0}, e{0};
	cin >> b >> e;
	bool isValid{false};

	for(int i=b; i<=e; ++i)
		if(isKaprekar(i))
		{
			cout << i << " ";
			isValid = true;
		}

	if(!isValid)
		cout << "INVALID RANGE";

    return 0;
}
