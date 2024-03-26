/*
 * Title: Rudolf And The Imbalance
 * Rating: 1800
 * Code: 1941/F
 * URI: https://codeforces.com/problemset/problem/1941/F
 */



#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

using namespace std;

bool debug = false;

void solve() {
  bool changed = false;
  int n, m, k, counter = 0;
  cin >> n >> m >> k;

  // diff, i value
  pair<int, int> largest_diff = make_pair(-1, -1);
  pair<int, int> second_largest_diff = make_pair(-1, -1);

  // Load in the arrays
  int a[n], d[m], f[k];
  cin >> a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];

    if (a[i] - a[i - 1] > largest_diff.first) {
      second_largest_diff = largest_diff;
      largest_diff = make_pair(a[i] - a[i - 1], i);
      counter = 0;
    } else if (a[i] - a[i - 1] == largest_diff.first)
      counter++;
    else if (a[i] - a[i - 1] > second_largest_diff.first)
      second_largest_diff = make_pair(a[i] - a[i - 1], i);
  }

  int best_diff_found = largest_diff.first;

  for (int i = 0; i < m; i++)
    cin >> d[i];
  for (int i = 0; i < k; i++)
    cin >> f[i];

  // Best case scenario, we decrease one of them
  if (counter > 0) {
    cout << largest_diff.first << '\n';
    return;
  }

  // now we can sort one of them (the shortest would be ideal)
  // O(m log(m))
  sort(d, d + m);

  if (debug) {
    for (int i = 0; i < m; i++)
      cout << d[i] << ' ';
    cout << '\n';
  }

  double ideal =
      (double)a[largest_diff.second - 1] + ((double)largest_diff.first / 2.0);

  for (int i = 0; i < k; i++) {
    int function = f[i];
    double find = ideal - function;

    if (debug) {
      printf("If f_i = %i, then: ", function);
    }

    int l = 0;
    int h = m - 1;
    while (true) {
      if (h - l < 2)
        break;

      int index = l + (h - l) / 2;

      if (d[index] > find)
        h = index;
      else
        l = index;
    }

    // Is it l or h ?
    pair<int, int> pos = make_pair(function + d[h], function + d[l]);

    if (pos.first < a[largest_diff.second - 1] ||
        pos.first > a[largest_diff.second])
      pos.first = -1;
    else
      pos.first = max(a[largest_diff.second] - pos.first,
                      pos.first - a[largest_diff.second - 1]);

    if (pos.second < a[largest_diff.second - 1] ||
        pos.second > a[largest_diff.second])
      pos.second = -1;
    else
      pos.second = max(a[largest_diff.second] - pos.second,
                       pos.second - a[largest_diff.second - 1]);

    if (debug)
      printf("(%i, %i)", pos.first, pos.second);

    int now = min(pos.first, pos.second);
    if (now == -1)
      now = max(pos.first, pos.second);

    if (now != -1)
      best_diff_found = min(best_diff_found, now);
  }
  if (debug)
    printf("second largest: %i\n", second_largest_diff.first);

  cout << max(min(best_diff_found, largest_diff.first),
              second_largest_diff.first)
       << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
