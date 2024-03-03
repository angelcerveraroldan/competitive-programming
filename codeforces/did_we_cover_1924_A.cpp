/*
 * Title: Did We Get Everything Covered ?
 * Rating: 1500
 * Code: 1924/A
 * URI: https://codeforces.com/problemset/problem/1924/A
 * */

#include <iostream>

using namespace std;

int n, k, m;
string input;

void solve()
{
  cin >> n >> k >> m >> input;
 
  // This will be 000..000111...111 with k ones
  uint32_t all_found = (1U << k) - 1U;

  // Keep track of a string that may not be contained as a subseries of
  // the string
  string not_in = "";

  int current = 0;

  // Found is used a way to keep track of all the characters that have been 
  // found so far
  uint32_t found = 0;

  for (char c : input)
  {
    uint32_t id = c - 'a';
    found |= ((uint32_t)1 << id);
  
    // If we have found all the chars in the alphabet
    if (found == all_found) 
    {
      not_in = not_in + c;
      found = 0;
      current ++;
    }

    // We are finished early
    if (current == n)
    {
      cout << "Yes\n";
      return;
    }
  }
  
  // If we get here, that means that there is some 
  // substring that cannot be obtained, we may be missing
  // some letters
  //
  // This will add a letter such that no matter what we add after it
  // it will not be a subsequence
  for (int i = 0; i < k; i ++)
  {
    if ((found & (1U << i)) == 0) 
    {
      not_in = not_in + (char) (i + 'a');
      break;
    }
  }

  // If its too short we can just add some padding
  // we will add the letter 'a' since that comes first 
  // in the alphabet
  while (not_in.size() < n)
    not_in += 'a';

  cout << "No\n" << not_in + "\n";
}

int tests;
int main()
{
  cin >> tests;
  for(int t = 0; t < tests; t ++) solve(); 
}
