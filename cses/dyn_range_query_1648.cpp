#include <iostream>
#include <vector>

#define ll long long unsigned int

using namespace std;

ll tree[200001];
int input[200001];

void add(int index, int delta) {
	for (; index < 200001; index = index | (index + 1)) 
		tree[index] += delta;
}

ll sum_to(int index) 
{
	ll sum = 0;
	while (index > 0)
	{
		sum += tree[index];
		index = (index & (index + 1)) - 1;
	}
	if (index == 0) sum+=tree[0];
	return sum;
}

int main()
{
	int n, q, val; cin >> n >> q;

	// Build the tree
	// O(N log N) -- Slow ?
	for (int i = 0; i < n; i ++)
	{
		cin >> val; add(i, val);
		input[i] = val;
	}

	int kind, a, b;
	while (q--)
	{
		cin >> kind >> a >> b;
		// Change value at index a to b
		if (kind == 1)
		{	
			add(a-1, b - input[a-1]);
			input[a-1] = b;
		}
		else if (kind == 2)
			cout << (sum_to(b-1) - sum_to(a-2)) << endl;
	}
}
