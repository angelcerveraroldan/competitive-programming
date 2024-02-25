/*
 * Title: Queue Sort
 * Rating: 1300
 * Code: 1899/E
 * URI: https://codeforces.com/problemset/problem/1899/E
 **/

#include <iostream>
#include <utility>

using namespace std;

int tests, n;

void solve()
{
	cin >> n;
	int arr[n];
			
	cin >> arr[0];
	pair<int, int> smallest = make_pair(0, arr[0]);
	bool sorted = true;

	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i - 1] > arr[i]) sorted = false;

		if (arr[i] < smallest.second) {
			smallest = make_pair(i, arr[i]);
			sorted = true;
		}
	}

	(sorted) ? cout << smallest.first << "\n" : cout << "-1\n";
}

int main()
{
	cin >> tests;
	for (int test = 0; test < tests; test ++) solve();
}
