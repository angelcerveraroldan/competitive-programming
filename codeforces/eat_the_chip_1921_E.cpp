/*
 * Title: Eat The Chip
 * Rating: 1600
 * Code: 1921/E
 * URI: https://codeforces.com/problemset/problem/1921/E
 **/

#include <iostream>
#include <cstdlib>

using namespace std;


int tests; 
int h, w, xa, ya, xb, yb;


void solution()
{
	cin >> h >> w >> xa >> ya >> xb >> yb;

	// Check what the difference in the y axis is.
	int deltay = abs(ya - yb);
	int deltax = abs(xa - xb);

	// Game ends after m moves
	int m = deltax; 
	int diff = m / 2;

	xa += diff;
	xb -= diff;

	// If m is even, that means that Bob may win, if m is odd, then Alice may wins
	if (m % 2 == 0)
	{
		// Can Alice run away ?
		//
		// Attempt to move down and away from bob
		if (ya < yb) 
		{
			ya = max(1, ya - diff);
			yb = max(1, yb - diff);
		}
		else if (ya > yb)
		{
			ya = min(w, ya + diff);
			yb = min(w, yb + diff);
		}

		(xa == xb && ya == yb) ? cout << "Bob\n" : cout << "Draw\n";
	}
	else 
	{
		// Can Bob run away ?
		//
		// Attempt to move up and away from alice
		xa ++;
		if (ya < yb) 
		{
			ya = min(w, ya + diff + 1);
			yb = min(w, yb + diff);
		}
		else if (ya > yb)
		{
			ya = max(1, ya - diff - 1);
			yb = max(1, yb - diff);
		}

		(xa == xb && ya == yb) ? cout << "Alice\n" : cout << "Draw\n";
	}
}

int main()
{
	cin >> tests; 
	for (int k = 0; k < tests; k ++)
		solution();
}
