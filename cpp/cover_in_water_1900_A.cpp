/*
 * Title: Cover In Water
 * Rating: 800
 * Code: 1900/A
 * URI: https://codeforces.com/problemset/problem/1900/A
 **/

#include <iostream>
#include <string>

using namespace std;

int t;

void solve()
{
	bool m1, m2, early_f;
	m1 = m2 = early_f = false;
	
	int len;
	
	string str;

	cin >> len >> str;
	
	int holes = 0;
	for (int i = 0; i < len; i ++)
	{
		// Read in one character
		char c = str[i]; 
			
		if (c == '.') { 
			holes ++;
			if (m1 && m2) { early_f = true ; break; }

			m2 = m1;
			m1 = true; 
		} else { m2 = m1; m1 = false; }
	}

	(early_f) ? cout << "2\n" : cout << holes << "\n";
}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i ++) 
		solve();
}
