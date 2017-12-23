/*
 * main.cpp
 *
 *  Created on: Apr 25, 2017
 *      Author: jerzy
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <algorithm>
using namespace std;

void maxPermutation(vector<unsigned long>& v, unsigned long K)
{
   unsigned long i{0}, k{0}, N{v.size()};

   while(i<N && k<K)
   {
      auto it = find(begin(v) + i, end(v), N-i);
      if(it != (begin(v) + i)) {
         iter_swap(it, (begin(v)+i));
         ++k;
      }
      ++i;
   }
}

int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   unsigned long N{0}, K{0}, tmp{0};
   cin >> N >> K;

   vector<unsigned long> v;
   for(unsigned long i=0; i<N; ++i)
   {
      cin >> tmp;
      v.push_back(tmp);
   }

   maxPermutation(v, K);
   copy(begin(v), end(v), ostream_iterator<unsigned long>(cout, " "));

   return 0;
}
