#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n{0}, tmp{0};
    cin >> n;
    vector<int> vec;
    for(int i=0; i<n; ++i) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    int inserted = vec.back();
    bool isDone{false};
    for(int i=vec.size()-2; i>=0; --i) {
        if(vec[i] > inserted) {
            vec[i+1] = vec[i];
        }
        else {
            vec[i+1] = inserted;
            isDone=true;
            break;
        }

        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    if(!isDone)
        vec[0] = inserted;
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));


    return 0;
}
