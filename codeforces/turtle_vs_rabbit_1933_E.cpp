#include <iostream>

using namespace std;

void solve()
{
	int tmp, n; cin >> n; 

	unsigned int partitions[n+1];
	partitions[0] = 0;

	for (int i = 1; i <= n; i ++) 
	{
		cin >> tmp;
		partitions[i] = tmp + partitions[i-1];
	}

	int index, queries, l, u;
	unsigned int value;
	cin >> queries;
	while (queries --)
	{
		cin >> l >> u; 

		// Now we calculate the ideal value of n
		double ideal = 
			0.5 * ( (2.0 * (double) u) + 1.0 )
			+ partitions[l - 1];
		
		// Now we find the index containing the number closest to ideal
		
		int lower = l;
		int upper = n;
		while (true)
		{
			// cout << "Between " << lower << " and " << upper << endl;
			index = lower + (upper-lower)/2;
			value = partitions[index];

			if (value < ideal) lower = index;
			else upper = index;

			if (upper - lower < 2) 
				break;
		}
		
		double upper_dif = abs((double) partitions[upper] - ideal);
		double lower_dif = abs((double) partitions[lower] - ideal);

		if (upper_dif < lower_dif)
			cout << upper << " ";
		else cout << lower << " ";
	}
	cout << "\n";
}

int main()
{
	int t; cin >> t; 
	while (t--) solve();
}

