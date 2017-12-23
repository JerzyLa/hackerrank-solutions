#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector< int > a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }

    cout << double( count_if(begin(a), end(a), [](const auto& a){ return a > 0;}) ) / n << endl;
    cout << double( count_if(begin(a), end(a), [](const auto& a){ return a < 0;}) ) / n << endl;
    cout << double( count_if(begin(a), end(a), [](const auto& a){ return a == 0;}) ) / n << endl;

    return 0;
}
