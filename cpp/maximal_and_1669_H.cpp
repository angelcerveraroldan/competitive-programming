/*
 * Title: Maximal AND
 * Rating: 1300
 * Code: 1669/H
 * URI: https://codeforces.com/problemset/problem/1669/H
 **/

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int n, k, num;

void solve()
{
	cin >> n >> k;
	uint32_t numbers[n];
	vector<int> zeros_at(31, 0);

	for (int i = 0; i < n; i ++)
	{
		cin >> num;
		numbers[n] = num;

		for (int i = 0; i <= 30; i ++) { if ( !(num & (1 << i)) ) zeros_at[i] ++; }
	}

	// Now we need to go from right to left
	// and if the number of 0's is smaller than 
	// k, we make k smallest, and set that to a 1

	uint32_t o = 0;
	for (int i= 30; i >= 0; i--) 
	{
		if (zeros_at[i] <= k) 
		{
			k -= zeros_at[i];
			o |= (1 << i);
		}
	}

	cout << o << "\n";

}

int tests;

int main()
{
	cin >> tests;
	for (int test = 0; test < tests; test++) solve();
}
