/*
 * Title: Shashlik Cooking
 * Rating: 1300 
 * Code: 1040/B
 * URI: https://codeforces.com/problemset/problem/1040/B
 **/

#include <iostream>
#include <cmath>

using namespace std;

int n, k;
int main()
{
  cin >> n >> k;
  int needed = 
    ceil( ((float) n)/((float)((2*k) + 1)) );

  cout << needed << '\n'; 

  int indexes[needed];
  for (int i = 0; i < needed; i ++) indexes[i] = (2*k + 1) * i;

  int leftover = n - ( (needed - 1)*(2*k + 1) + (k + 1));
  
  for (const auto &v : indexes) cout << (1+v+max(0,leftover)) << ' ';
  cout << '\n';
}
