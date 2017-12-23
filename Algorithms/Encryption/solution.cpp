#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cctype>
#include <math.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string str;
	getline(cin, str);

	// remove spaces
	str.erase(remove_if(begin(str), end(str), ::isspace), end(str));

	// create grid
	auto len = str.size();
	auto fl = floor(sqrt(len));
	auto cl = ceil(sqrt(len));
	unsigned rows{0}, cols{0};

	if(fl*fl >= len)
	{
		rows = (cols = fl);
	}
	else if(fl*cl >= len)
	{
		rows = fl;
		cols = cl;
	}
	else
	{
		rows = (cols = cl);
	}

	// print result
	for(unsigned i=0; i<cols; ++i)
	{
		for(unsigned j=0; j<rows; ++j)
			if(cols*j+i < str.size())
				cout << str[cols*j+i];
		cout << " ";
	}

    return 0;
}
