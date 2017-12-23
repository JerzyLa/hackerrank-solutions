#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

string possible(vector<vector<unsigned long>>& m)
{
   vector<unsigned long> numOfBallsInContainers;
   for(const auto& el : m)
	   numOfBallsInContainers.push_back(accumulate(begin(el), end(el), (unsigned long)0));

   vector<unsigned long> numOfSameColorBalls;
   for(unsigned i=0; i<m.size(); ++i)
   {
	  unsigned long tmp{0};
      for(unsigned j=0; j<m.size(); ++j)
         tmp += m[j][i];

      numOfSameColorBalls.push_back(tmp);
   }

   bool isValid = is_permutation(begin(numOfBallsInContainers), end(numOfBallsInContainers), begin(numOfSameColorBalls));

   if(isValid)
	   return "Possible";

   return "Impossible";
}

int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   unsigned queries{0}, n{0};
   cin >> queries;

   vector<vector<unsigned long>> m;
   vector<string> results;

   for (unsigned i=0; i<queries; ++i)
   {
      cin >> n;
      for(unsigned k=0; k<n; ++k)
      {
         unsigned long tmp{0};
         vector<unsigned long> vec;
         for(unsigned l=0; l<n; ++l)
         {
            cin >> tmp;
            vec.push_back(tmp);
         }

         m.push_back(vec);
      }

      results.push_back( possible(m) );
      m.clear();
   }

   copy(begin(results), end(results), ostream_iterator<string>(cout, "\n"));

   return 0;
}
