/*
 * Title: Choose the Different Ones!
 * Rating: 1000
 * Code: 1927.C
 * URI: https://codeforces.com/problemset/problem/1927/C
 **/

#include <iostream>
#include <unordered_map>

using namespace std;

int test_count; 
int f_len, s_len, k, tmp;

int main()
{
	cin >> test_count; 
	for (int l = 0; l < test_count; l ++)
	{
		cin >> f_len >> s_len >> k;
		unordered_map<int, bool> fst, snd;

		for (int i = 0; i < f_len; i ++) 
		{
			cin >> tmp;
			if (tmp <= k) fst[tmp] = true;
		}

		for (int i = 0; i < s_len; i ++) 
		{
			cin >> tmp;
			if (tmp <= k) snd[tmp] = true;
		}
	

		int fst_count = 0;
		int snd_count = 0;
		int both = 0; 

		for (int i = 1; i <= k; i ++)
		{
			if (!fst[i] && !snd[i]) break;
			else if ( fst[i] && !snd[i]) fst_count ++;
			else if (!fst[i] &&  snd[i]) snd_count ++;
			else if ( fst[i] &&  snd[i]) both ++;
		}

		int total = fst_count + snd_count + both; 
		(total == k && fst_count <= k/2 && snd_count <= k/2) ? cout << "YES\n" : cout << "NO\n";
	}
}

