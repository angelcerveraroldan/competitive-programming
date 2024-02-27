#include <iostream>
#include <cstdint>
#include <bitset>

#define ONE ((uint64_t) 1)

using namespace std;

int count_ones(uint64_t u)
{
	int counted_ones = 0;
	for (int m = 0; m < 64; m++)
	{
		if ((u & (ONE << m)) != 0) counted_ones ++; 
	}
	return counted_ones;
}


void solve()
{
	int n, set_size;
	uint64_t tmp, intersection = 0;

	cin >> n;
	uint64_t sets[n];

	for(int i = 0; i < n; i ++)
	{
		cin >> set_size;
		sets[i] = 0;

		for (int j = 0; j < set_size; j++) 
		{ 
			cin >> tmp;
			sets[i] |= (ONE << (tmp - 1)); 
			// Keep track of the intersection of all element in the set
			intersection |= (ONE << (tmp - 1));
		}
	}

	// Find the union of all sets not containing one
	// Find the union of all sets not containing two
	// ...
	
	uint64_t intersections_not_containing[50];
	for (uint64_t s = 0; s < 50; s ++)
	{
		uint64_t at_i = 0;
		for (uint64_t x : sets)
		{
			if ( (x & (ONE << s)) == 0 ) at_i |= x;
		}

		intersections_not_containing[s] = at_i;
	}
	
	int index = -1;
	int ones = -1;
	for (uint64_t x : intersections_not_containing)
	{
		if (x == intersection) continue;
		
		int n_ones = count_ones(x);
		if (n_ones > ones)
			ones = n_ones;
	}
	cout << ones << "\n";
}	

int tests;
int main()
{
	cin >> tests;
	for (int t = 0; t < tests; t++) solve();
}
