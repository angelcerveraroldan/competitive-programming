#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int len, tmp;
void solve()
{
	// Load in the array of numbers
	cin >> len;
	int times[10]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	for (int i = 0; i < len; i ++) 
	{
		cin >> tmp;
		times[tmp % 10] ++;
	}

	vector<int> numbers;
	for (int i = 0; i < 10; i ++) 
		for (int j = 0; j < min(3, times[i]); j ++) 
			numbers.push_back(i);

	int len = numbers.size();
	for (int i = 0; i < len-2; i ++)
		for (int j = i + 1; j < len-1; j ++)
			for (int k = j + 1; k < len; k ++)
				if ((numbers[i] + numbers[j] + numbers[k]) % 10 == 3) {
					cout << "YES\n";
					return;
				}

	cout << "NO\n";
}


int tests;
int main()
{
	cin >> tests;
	for (int test = 0; test < tests; test ++) solve();
}
