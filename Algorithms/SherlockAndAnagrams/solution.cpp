#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

using Key = array<int, 26>;

template<typename It>
Key CreateKey(It b, It e)
{
  Key key;
  while(b!=e) {
    ++key[*b-'a'];
    ++b;
  }

  return key;
}

int solution(string s) {
  set<Key> m;
  int count{0};
  /// for all substrings
  for(int pos=0; pos<s.size(); ++pos)
    for(int len=1; len<s.size()-pos+1; ++len)
     {
       Key key = CreateKey(s.begin() + pos, s.begin()+pos+len);
       if(m.find(key) != m.end())
          ++count;
       else
          m.insert(key);
     }

   return count;
}

int main() {
    int testCases{0};
    cin >> testCases;

    for(int i=0; i<testCases; ++i)
    {
      string s;
      cin >> s;
      cout << solution(s) << endl;
    }

    return 0;
}
