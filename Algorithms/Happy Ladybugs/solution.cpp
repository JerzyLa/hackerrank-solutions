#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isInHappyOrder(string s)
{
    if(*(s.begin()) != *(s.begin()+1))
        return false;

    if(*(s.rbegin()) != *(s.rbegin()+1))
        return false;
    
    for(size_t i=1; i<s.size()-1; ++ i)
    {
        if((s[i] != s[i-1]) && (s[i] != s[i+1]) )
            return false;
    }

    return true;
}

bool solution(string s)
{
    uint arr[26] = {0};
    bool isEmpty = false;

    for_each(s.begin(), s.end(), [&](const auto& el) { 
        if(el == '_') 
            isEmpty = true;
        else 
            ++arr[el-65]; 
    });

    auto it = find(begin(arr), end(arr), 1);
    if(it != end(arr))
        return false;
    
    if(isEmpty)
        return true;

    return isInHappyOrder(s);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    uint testcases;
    cin >> testcases;
    for(size_t i=0; i<testcases; ++i)
    {
        uint numOfCells;
        string cells;

        cin >> numOfCells;
        cin >> cells;

        bool result = solution(cells);
        cout << (result ? "YES\n" : "NO\n");
    }

    return 0;
}
