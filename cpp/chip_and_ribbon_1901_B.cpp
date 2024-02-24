/*
 * Title: Chip And Ribbon
 * Rating: 1100
 * Code: 1901/B
 * URI: https://codeforces.com/problemset/problem/1901/B
 **/


#include <iostream>
#include <cstdint>

using namespace std;

int length, back_to, test_num;

void solve()
{
	cin >> length;

	int desired[length];
	for (int i = 0; i < length; i ++) cin >> desired[i];

	uint64_t teleport = desired[0] - 1;
	for (int i = 1; i < length; i ++)
	{
		if (desired[i - 1] < desired[i]) 
			teleport += (desired[i] - desired[i - 1]);
	}
	cout << teleport << "\n";
}

int main()
{
	cin >> test_num;
	for (int test = 0; test<test_num; test++) solve();
}
