#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   unsigned long toys{0}, money{0}, tmp{0};
   cin >> toys >> money;
   vector<unsigned long> v;

   for(unsigned long i=0; i<toys; ++i)
   {
      cin >> tmp;
      v.push_back(tmp);
   }

   sort(begin(v), end(v));
   unsigned long spend{0}, i{0};

   for(const auto& el : v)
   {
     spend += el;
     if(spend <= money)
        ++i;
     else
        break;
   }

   cout << i << endl;

   return 0;
}
