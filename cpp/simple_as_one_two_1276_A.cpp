/*
 * Title: Simple As One And Two
 * Rating: 1400 
 * Code: 1276/A
 * URI: https://codeforces.com/problemset/problem/1276/A
 **/

#include <iostream>
#include <vector>

#define MATCH_ONE (c == 'o' && cm == 'n' && cmm == 'e')
#define MATCH_TWO (c == 't' && cm == 'w' && cmm == 'o')

using namespace std;

string input;
void solve()
{
  cin >> input;
  int ln = input.length();

  vector<int> removed_index;
  int bestests[ln];
  for (int i = 0; i < ln; i++) bestests[i] = 0;
  
  for (int i = 2; i < ln; i ++)
  {
    char cmm = input[i  ];
    char cm  = input[i-1];
    char c   = input[i-2]; 

    if ( MATCH_ONE || MATCH_TWO )
    {
      int remindex = i;
      if (i == 2) bestests[i] = 1;
      // Remove first letter of "one/two" and cancel the prior removal
      else if (bestests[i-1] > bestests[i-3])
      {
        removed_index.pop_back();
        remindex --;
        bestests[i] = bestests[i-3]+1;
      }
      // Remove middle letter in the "one"/"two"
      else bestests[i] = bestests[i-1]+1;

      removed_index.push_back(remindex);
    }
    else bestests[i] = bestests[i-1];
  }

  cout << bestests[ln - 1] << "\n";
  for (auto const &n : removed_index) cout << n << ' ';
  cout << '\n';
}

int tests;
int main()
{
  cin >> tests;
  for (int test = 0; test < tests; test++) solve();
}
