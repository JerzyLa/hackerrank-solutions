#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }

    sort(c.begin(), c.end());
    int max_distance{0};
    for(size_t i=0; i<c.size()-1; ++i)
    	max_distance = max(c[i+1]-c[i], max_distance);

    max_distance /= 2;
    max_distance = max(max_distance, c[0]);
    max_distance = max(max_distance, n-c[m-1]-1);

    cout << max_distance << endl;

    return 0;
}
