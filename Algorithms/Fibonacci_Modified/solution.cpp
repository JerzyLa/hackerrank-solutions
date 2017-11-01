#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

class BigInteger
{
public:
	BigInteger()
	{}

	BigInteger(long i)
	{
		add(0, i);
	}

	BigInteger(const BigInteger&) = default;
	BigInteger(BigInteger&&) = default;
	BigInteger& operator=(const BigInteger&) = default;
	BigInteger& operator=(BigInteger&&) = default;

	BigInteger operator+(const BigInteger& val)
	{
		BigInteger result;
		for(size_t i=0; i<max(val.size(), size()); ++i)
		{
			result.add(i, get(i) + val.get(i));
		}

		return result;
	}

	BigInteger operator*(const BigInteger& val)
	{
		BigInteger result;
		for(size_t i=0; i<val.size(); ++i)
		{
			for(size_t j=0; j<size(); ++j)
			{
				result.add(i+j, (long)get(j) * (long)val.get(i));
			}
		}

		return result;
	}

	string toString() const
	{
		stringstream ss;
		ss << vec.back();
		for(auto it=vec.rbegin()+1; it!=vec.rend(); ++it)
			ss << setfill('0') << setw(9) << *it;

		return ss.str();
	}

private:
	void add(size_t i, long val)
	{
		while(size() <= i)
			vec.push_back(0);

		long newVal = (vec[i] + val);
		vec[i] = newVal % 1000000000;
		if(newVal >= 1000000000)
			add(i+1, newVal/1000000000);
	}

	int get(size_t i) const
	{
		if(size() <= i)
			return 0;
		return vec[i];
	}

	size_t size() const {return vec.size();}

private:
	/// every integer 0 - 999.999.999
	vector<int> vec;
};


ostream& operator<<(ostream& os, const BigInteger& bi)
{
	return os << bi.toString();
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a,b,n;
    cin >> a >> b >> n;
	BigInteger t1(a), t2(b);

    BigInteger result{0};
    for(int i=2; i<n; ++i) {
    	result = t1+(t2*t2);
    	t1 =t2;
    	t2 = result;
    }

    cout << result << endl;

	return 0;
}

