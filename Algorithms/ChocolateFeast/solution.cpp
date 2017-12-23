#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int t{0}, n{0}, c{0}, m{0};
	cin >> t;
	vector<int> v;

	for(int i=0; i<t; ++i)
	{
		cin >> n >> c >> m;
		int eaten = n/c;
		int wrappers = eaten;
		int exchanged = wrappers/m;

		while(exchanged > 0)
		{
			eaten += exchanged;
			wrappers += exchanged - exchanged*m;
			exchanged = wrappers/m;
		}

		v.push_back(eaten);
	}

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));

    return 0;
}
