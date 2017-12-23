#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	vector<unsigned long> vec;
    unsigned long tmp{0};

	for(unsigned i=0; i<5; ++i){
		cin >> tmp;
		vec.emplace_back(tmp);
	}

	vector<unsigned long> results;
	unsigned long sum = accumulate(begin(vec), end(vec), (unsigned long)0);
	for(int i=0; i<5; ++i)
		results.push_back(sum-vec[i]);

	cout << *min_element(begin(results), end(results)) << " "
		 << *max_element(begin(results), end(results)) << endl;

    return 0;
}
