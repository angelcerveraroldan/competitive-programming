/*
 * Title:  Watering an Arrays
 * Rating: 1600
 * Code: 1971/C
 * URI: https://codeforces.com/problemset/problem/1917/C
 */

#include <iostream>

using namespace std;


void solve() 
{
  int n, k, d; cin >> n >> k >> d;
  int add[2001] = {};
  int arr[n];
  int range[k];

  // Load in both arrays
  for (int i = 0; i < n; i ++) cin >> arr[i];
  for (int i = 0; i < k; i ++) cin >> range[i];
  
  // The worse case scenario score is:
  int best_yet = (d - 1)/2;

  for (int turn = 0; turn < min(2 * n, d); turn ++)
  {
    int add_up_to = range[turn % k];

    // In this turn we can do one of two things, 
    // one is add the score we would get if we summed
    // all the elements now
    int sum = 0;
    int delta = turn;
    for (int i = 0; i < n; i ++) 
    {
      delta += add[i];
      if (delta + arr[i] == i + 1) sum ++;
    }

    best_yet = max(best_yet, sum + (d - (turn + 1))/2);
    add[add_up_to] --;
  }
 
  cout << best_yet << endl;
}

int main()
{
  int t; cin >> t;
  while (t --) solve();
}
