/*
 * Title: Good Subarrays
 * Rating: 1600
 * Code: 1398/C
 * URI: https://codeforces.com/problemset/problem/1398/C
 **/


#include <iostream>
#include <unordered_map>

#define ll long long

using namespace std;

void solve()
{
  int n; cin >> n;
  string inpt; cin >> inpt;

  ll ans = 0;
  unordered_map<ll, ll> cnt;

  ll tmp, indexed_val, sum = 0;
  for (int i = 1; i <= n; i ++)
  {
    cnt[sum - i] ++;
    tmp = inpt[i - 1] - '0';
    sum += tmp;
    indexed_val = sum - i - 1; 
    ans += cnt[indexed_val];
  }

  cout << ans << endl; 
}

int main()
{
  int t; cin >> t;
  while (t--) solve();
}

/*
 * Thinking 
 *
 * sum(l - r) 
 *  = sum_(0 - r) - sum(0 - (l - 1)) 
 *  = r - l + 1
 *
 * sum_(0 - r) - r =  sum(0 - (l - 1)) - l + 1
 * (sum_(0 - r) - r) -  (sum(0 - (l - 1)) - l) = 1
 *                      ^^^^^^^^^^^^^^^^^^^^^^
 *                       index this and count
 * */


