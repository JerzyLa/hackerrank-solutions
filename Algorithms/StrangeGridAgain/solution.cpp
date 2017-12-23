#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long row, val;
    unsigned col;

    cin >> row;
    cin >> col;

    if(row%2 == 0)
    {
       val = row*5 + (col-1)*2 - 9;
    }
    else
    {
       val = row*5 + (col-1)*2 - 5;
    }

    cout << val;

    return 0;
}
