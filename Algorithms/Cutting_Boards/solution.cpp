#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	unsigned q, m, n;
	cin >> q;
	for(unsigned i=0; i<q; ++i) {
		cin >> m >> n;
		vector<unsigned> cy(m-1);
		vector<unsigned> cx(n-1);
		for(unsigned j=0; j<m-1; ++j)
			cin >> cy[j];
		for(unsigned j=0; j<n-1; ++j)
			cin >> cx[j];

		/// solution
		sort(cy.begin(), cy.end(), greater<unsigned>());
		sort(cx.begin(), cx.end(), greater<unsigned>());

		auto max_y = cy.begin();
		auto max_x = cx.begin();

		unsigned long long cutX{0}, cutY{0}, result{0};
		while(max_y != cy.end() || max_x != cx.end()) {
			if(max_y != cy.end() && (max_x == cx.end() || *max_y >= *max_x)) {
				result = (result + (*max_y)*(cutX + 1))%1000000007;
				++cutY;
				++max_y;
			}
			else if(max_x != cx.end() && (max_y == cy.end() || *max_y < *max_x)) {
				result = (result + (*max_x)*(cutY + 1))%1000000007;
				++cutX;
				++max_x;
			}
		}

		cout << result << endl;
	}

    return 0;
}
