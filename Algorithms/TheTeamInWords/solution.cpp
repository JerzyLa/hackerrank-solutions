#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<unsigned, string> numbers = {
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"},
		{5, "five"},
		{6, "six"},
		{7, "seven"},
		{8, "eight"},
		{9, "nine"},
		{10, "ten"},
		{11, "eleven"},
		{12, "twelve"},
		{13, "thirteen"},
		{14, "fourteen"},
		{15, "fifteen"},
		{16, "sixteen"},
		{17, "seventeen"},
		{18, "eighteen"},
		{19, "nineteen"},
		{20, "twenty"},
		{21, "twenty one"},
		{22, "twenty two"},
		{23, "twenty three"},
		{24, "twenty four"},
		{25, "twenty five"},
		{26, "twenty six"},
		{27, "twenty seven"},
		{28, "twenty eight"},
		{29, "twenty nine"}
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int hour{0}, minutes{0};
	cin >> hour >> minutes;

	if(minutes == 0)
		cout << numbers[hour] << " o' clock";
	else if(minutes == 1)
		cout << numbers[minutes] << " minute past " << numbers[hour];
	else if(minutes == 15)
		cout << "quarter past " << numbers[hour];
	else if(minutes > 1 && minutes < 30)
		cout << numbers[minutes] << " minutes past " << numbers[hour];
	else if(minutes == 30)
		cout << "half past " << numbers[hour];
	else if(minutes == 45)
		cout << "quarter to " << numbers[hour+1];
	else if(minutes > 30 && minutes < 59)
		cout << numbers[60-minutes] << " minutes to " << numbers[hour+1];
	else
		cout << numbers[60-minutes] << " minute to " << numbers[hour+1];

    return 0;
}
