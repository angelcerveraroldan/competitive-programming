// https://codeforces.com/contest/977/problem/F

#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
  int len;
  cin >> len;
  int a[len];

  int max_len = -1;
  int max_at = -1;
  unordered_map<int, int> best_case;

  for (int i = 0; i < len; i++) {
    cin >> a[i];
    int num = a[i];

    // save the fact that the number appeared
    best_case[num] = best_case[num - 1] + 1;

    if (best_case[num] > max_len) {
      max_len = best_case[num];
      max_at = i;
    }
  }

  int final_num = a[max_at];

  cout << max_len << '\n';

  int find = final_num - max_len + 1;

  for (int i = 0; i <= len && find <= final_num; i++) {
    if (a[i] == find) {
      cout << i + 1 << ' ';
      find++;
    }
  }

  cout << endl;
}
