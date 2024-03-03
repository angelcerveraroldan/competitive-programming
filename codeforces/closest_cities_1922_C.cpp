#include <iostream>
#include <utility>
#include <limits>

using namespace std;

int n, m;
int from, to; 

void solution()
{
	cin >> n; 

	int costsr[n];
	int costsl[n];
	int values[n];

	for (int i = 0; i < n; i++) cin >> values[i];	
	
	
	costsr[0] = 0;
	costsl[0] = 0;

	for (int i = 1; i < n; i ++) 
	{	
		if (i == 1) 
		{
			int r = values[i] - values[i-1];
			int ll;
			if (n > 2) ll = values[i+1] - values[i];
			else ll = std::numeric_limits<int>::max();
			costsr[i] = 1;
			if (r > ll) costsl[i] = costsl[i-1] + r;
			else costsl[i] = costsl[i-1] + 1;
			continue;
		}

		if (i == n-1)
		{
			int r = values[i] - values[i-1];
			int l = values[i-1] - values[i-2];
			costsl[i] = costsl[i-1] + 1;
			if (r > l) costsr[i] = costsr[i-1] + r;
			else costsr[i] = costsr[i-1] + 1;
			continue;
		}
		
		int r = values[i] - values[i-1];
		int l = values[i-1] - values[i-2];
		int ll = values[i+1] - values[i];

		if (r > l) costsr[i] = costsr[i-1] + r;
		else costsr[i] = costsr[i-1] + 1;

		if (r > ll) costsl[i] = costsl[i-1] + r;
		else costsl[i] = costsl[i-1] + 1;
	}

	cin >> m; 
	
	for (int i = 0; i < m; i ++)
	{
		cin >> from >> to;
		
		// Make input 0-indexed
		from --;
		to --;

		if (to > from) 
		{
			// cout <<  costsr[to] << " - " << costsr[from] << " = " << costsr[to] - costsr[from] << "\n"; 
			cout <<  costsr[to] - costsr[from] << "\n"; 
		} else
		{
			// cout <<  costsl[from] << " - " << costsl[to] << " = " << costsl[from] - costsl[to] << "\n"; 
			cout << costsl[from] - costsl[to] << "\n"; 
		}

	}
}

int tests;

int main()
{	
	cin >> tests;
	for (int x = 0; x < tests; x ++) solution();	
}
