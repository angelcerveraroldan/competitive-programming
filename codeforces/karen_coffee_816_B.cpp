/*
 * Title: Karen Coffee
 * Rating: 1400
 * Code: 816/B
 * URI: https://codeforces.com/problemset/problem/816/B
 */

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;

  map<int, int> range;
  int max_tmp = -1;
  int from, to;

  for (int i = 0; i < n; i++) {
    cin >> from >> to;
    range[from]++;
    range[to + 1]--;

    if (to > max_tmp)
      max_tmp = to;
  }

  // How many temps are accepted by k or more recipes
  int accepting_tmp[max_tmp + 1];
  accepting_tmp[0] = (range[0] >= k) ? 1 : 0;
  int accepted_by = 0;
  for (int i = 1; i <= max_tmp; i++) {
    accepted_by += range[i];
    accepting_tmp[i] = accepting_tmp[i - 1];
    if (accepted_by >= k)
      accepting_tmp[i]++;
  }

  for (int i = 0; i < q; i++) {
    cin >> from >> to;

    int af =
        (from - 1 < max_tmp) ? accepting_tmp[from - 1] : accepting_tmp[max_tmp];
    int at = (to < max_tmp) ? accepting_tmp[to] : accepting_tmp[max_tmp];

    cout << at - af << '\n';
  }
}
