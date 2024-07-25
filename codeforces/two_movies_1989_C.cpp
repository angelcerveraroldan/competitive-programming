#include <iostream>

using namespace std;

void solve()
{
	int tmp, people; cin >> people;
	int first[people];
	int second[people];

	for (int i = 0; i < people; i ++) 
	{
		cin >> tmp; 
		first[i] = tmp;
	}

	for (int i = 0; i < people; i ++) 
	{
		cin >> tmp; 
		second[i] = tmp;
	}
	
	// Score of the first and second movie
	int fs = 0;
	int ss = 0;
	int both_good = 0;
	int both_bad = 0;

	int f, s;
	for (int i = 0; i < people; i ++)
	{
		f = first[i];
		s = second[i];

		if (f == 1 && s == 1) both_good++;
		else if (s == 1) ss ++;
		else if (f == 1) fs ++;
		else if (f == -1 && s == -1) both_bad ++;
	}

	while (both_good != 0)
	{
		if (fs < ss) fs++; 
		else ss ++;
		both_good --;
	}

	while (both_bad != 0)
	{
		if (fs > ss) fs--; 
		else ss --;
		both_bad --;
	}

	cout << min(fs, ss) << endl;
}

int main()
{
	int t; cin >> t;
	while (t--) solve();
}
