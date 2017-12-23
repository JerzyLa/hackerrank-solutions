#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned candles_num{0}, tmp{0};
    cin >> candles_num;
    vector<unsigned> candlesHeight;
    for(int i=0; i<candles_num; ++i)
    {
        cin >> tmp;
        candlesHeight.push_back(tmp);
    }

    auto it = max_element(begin(candlesHeight), end(candlesHeight));
    cout << count(begin(candlesHeight), end(candlesHeight), *it);

    return 0;
}
