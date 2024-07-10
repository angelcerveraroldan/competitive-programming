#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map< int, vector<int> > mixing;
unsigned long int dp[200001];
unsigned long int purchase[200001];


unsigned long int min_price(int i) {
	if (dp[i] != -1) return dp[i];
	vector<int> mixes = mixing[i];
	
	if (mixes.size() != 0) {
		unsigned long int mix_price = 0;
		for (auto &p : mixing[i]) 
		{
			mix_price += min_price(p-1);
		}

		dp[i] = min(purchase[i], mix_price);
	} else {
		dp[i] = purchase[i];
	}

	return dp[i];
}

void solution()
{
	int tmp, n, k; cin >> n >> k;
	mixing.clear();

	for (int i = 0; i < n; i ++)
	{
		cin >> tmp;
		purchase[i] = tmp;
		dp[i] = -1;
	}

	for (int i = 0; i < k; i ++)
	{
		cin >> tmp;
		purchase[tmp - 1] = 0;
	}
	
	for (int i = 0; i < n; i ++)
	{
		cin >> tmp;
		if (tmp == 0) continue;

		vector<int> v(tmp);
		for (auto &x : v) cin >> x;
		mixing[i] = v;
	}

	for (int i = 0; i < n; i ++) cout << min_price(i) << " ";
	cout << "\n";
}

int main() {
	int tests; cin >> tests;
	while(tests--) solution();
}
