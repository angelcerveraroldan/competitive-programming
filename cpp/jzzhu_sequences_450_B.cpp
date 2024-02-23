/*
 * Title: Jzzhu and Sequences
 * Rating: 1300
 * Code: 450.B
 * URI: https://codeforces.com/problemset/problem/450/B
 * */

#include <iostream>
#include <cmath>

#define MODULUS 1000000007

using namespace std;

int main()
{
	int first, second, n, answer;
	cin >> first >> second;

	int third = second - first;

	cin >> n; 
	int k = n % 3;

	if (k == 1) answer = first;
	if (k == 2) answer = second;
	if (k == 0) answer = third;

	int sub = 0;
	while (n > 3) { n -= 3; sub ++; }
	answer *= pow(-1, sub);

	cout << ((answer % MODULUS) + MODULUS) % MODULUS << "\n";
}
