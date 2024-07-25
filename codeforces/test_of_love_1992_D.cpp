#include <iostream>
#include <string>

using namespace std;

void solve()
{
	int river_len, jump_len, swim_max;
	cin >> river_len >> jump_len >> swim_max;

	char inp;
	int current_position = 0;

	bool finished = false;
	for (int i = 1; i <= river_len; i++)
	{
		cin >> inp;
		if (finished) continue;

		// If we can jump to it, we do so
		if (inp == 'L')
		{
			swim_max -= max(0,(i - current_position - jump_len));
			current_position = i;
		}

		if (swim_max < 0) finished = true;
		if (inp == 'C' && (i - current_position) >= jump_len) finished = true;
	}

	// Now see, can we get to the very end ?
	if (!finished 
		&& (river_len + 1) - current_position - jump_len <= swim_max
	)    cout << "Yes\n"; 
	else cout << "No\n";
}

int main()
{
	int q; cin >> q;
	while (q--) solve();
}
