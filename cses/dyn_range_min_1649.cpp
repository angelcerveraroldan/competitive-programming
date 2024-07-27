#include <iostream>
#include <vector>

#define ui unsigned int

using namespace std;

int tree[18][200001];

void fill_row(int row, int size) {
	for (int r = 0; r < size; r ++) tree[row][r] = min(tree[row-1][2*r],tree[row-1][2*r + 1]);
}


void update(int index, int to)
{
	tree[0][index] = to;
	index <<= 1;
	for (int i = 1; i < 18; i ++)
	{
		tree[i][index] = min(tree[i-1][2*index], tree[i-1][2*index + 1]);
		index <<=1;
	}
}

void debug()
{
	for (int i = 1; i < 18; i ++)
	{
		for (int j = 0; j < 20; j ++)
		{
			cout <<tree[i][j] << ", ";
		}
		cout << endl;
	}
}

int main()
{
	int n, q, tmp; cin >> n >> q;
	for (int i = 0; i < n; i ++)
	{
		cin >> tmp;
		tree[0][i] = tmp;
	}

	for (int i = 1; i < 18; i ++) fill_row(i, n);

	debug();
}



