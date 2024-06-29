#include <iostream>
#include <map>

using namespace std;

void solve()
{
	int a, len; cin >> len;
	map<int, int> map;

	for (int i = 0; i < len; i ++)
	{
		cin >> a;
		map[a] ++;
	}
	

	int curr = 0;
	bool premature_finish = false;
	while (true)
	{
		if (map[curr] == 0) {
			cout <<  curr << endl;
			return;
		}

		if (map[curr] <  2) 
		{
			if (!premature_finish) premature_finish = true;
			else {
				cout  << curr << endl;
				return;
			}
		}

		curr ++;
	}
}

int main()
{
	int tests; cin >> tests;
	while (tests--) solve();
}
