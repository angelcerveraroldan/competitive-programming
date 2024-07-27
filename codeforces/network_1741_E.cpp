#include <iostream>

using namespace std;

bool valid[200001] = {true};
	
void solve()
{
	int len, a; cin >> len; 
	for (int i = 1; i <= len; i++) valid[i] = false;

	for (int i = 1; i <= len; i++)
	{
		cin >> a;
		if (valid[i-1] && (i+a <= len)) {
			// cout << "Setting " << i + a << " true" << endl; 
			valid[i + a] = true;
		}
		if ((i - (a + 1)) >= 0 && valid[i - (a + 1)]) valid[i] = true;
	}

	if (valid[len]) cout << "Yes" << endl;
	else            cout << "No"  << endl;
}

int main()
{
	int t; cin >> t;
	while (t--) 
	{
		// cout << "Test " << t << endl;
		solve();
	}
}
