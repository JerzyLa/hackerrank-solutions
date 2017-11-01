#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class IceCream {

    public:
        int flavor;
        int index;

        IceCream(int flavor, int index)
           : flavor(flavor), index(index)
        {}

        bool operator<(const IceCream& ice) {
           return (this->flavor < ice.flavor);
        }
};

int binarySearch(int first, int last, const vector<IceCream>& arr, int search) {
   int n = (last-first) / 2 + first;
   if(arr[n].flavor == search)
      return n;

   if(first == last && arr[first].flavor != search)
      return -1;

   if(arr[n].flavor < search)
      return binarySearch(n+1, last, arr, search);
   else
      return binarySearch(first, n, arr, search);
}

int main() {
    int t{0}, m{0}, n{0}, flavor{0};

    cin >> t;
    for(int i=0; i<t; ++i) {
       cin >> m;
       cin >> n;
       vector<IceCream> vec;
       vec.reserve(n);

       for(int index=1; index<=n; ++index) {
          cin >> flavor;
          vec.emplace_back(flavor, index);
       }

       sort(begin(vec), end(vec));
       for(int j=0; j<vec.size(); ++j) {
          int search = m - vec[j].flavor;

          if(search >= vec[j].flavor) {
             int index = binarySearch(j+1, vec.size(), vec, search);
             if(index != -1) {
                cout << min(vec[j].index, vec[index].index) << " " << max(vec[j].index, vec[index].index) << endl;
                break;
             }
          }
       }
    }
}
