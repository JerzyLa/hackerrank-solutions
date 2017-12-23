#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char separator;
    string str;
    unsigned hour{0}, minute{0}, second{0};
    cin >> hour >> separator >> minute >> separator >> second >> str;

    if(str == "AM" && hour == 12)
        hour = 0;
    else if(str == "PM" && hour != 12)
        hour += 12;

    printf("%02d:%02d:%02d", hour, minute, second);

    return 0;
}
