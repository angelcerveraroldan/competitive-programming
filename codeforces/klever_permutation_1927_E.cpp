#include <iostream>

using namespace std;

void solve()
{
	int n, k; cin >> n >> k;
	int height = n / k; 
	if (n % k != 0) height ++; 

	int data[n];

	int max = n;
	int min = 1;

	for (int i = 0; i < k; i ++) 
	{
		if (i % 2 == 0)
		{
			int j = i; 
			while (j < n)
			{
				data[j] = max; 
				max --;
				j += k;
			} 
		}
		else
		{
			int j = i; 
			while (j < n)
			{
				data[j] = min; 
				min ++;
				j += k;
			} 
		}
	}	

	for (int i = 0; i < n; i ++) cout << data[i] << ' ';
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while (t --) solve();
}
