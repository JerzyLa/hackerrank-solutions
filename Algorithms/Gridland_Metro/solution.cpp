#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long merge(vector<pair<int,int>>& v) {
	long result{0};
	sort(begin(v), end(v), [](const auto& a, const auto& b){ return a.first < b.first; });

	int a = v.begin()->first;
	int b = v.begin()->second;
	for(auto it = begin(v)+1; it != end(v); ++it) {
		if(it->first <= b && b < it->second)
			b = it->second;
		else if(it->first > b) {
			result += b-a+1;
			a = it->first;
			b = it->second;
		}
	}

    result += b-a+1;
	return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long N, M, K, R, C1, C2;
	cin >> N >> M >> K;
	map<int, vector<pair<int,int>>> reils;

	for(int i=0; i<K; ++i) {
		cin >> R >> C1 >> C2;
		reils[R].push_back(make_pair(C1,C2));
	}

	long free = N*M;
	for(auto& entry : reils)
		free -= merge(entry.second);
    cout << free << endl;

    return 0;
}
