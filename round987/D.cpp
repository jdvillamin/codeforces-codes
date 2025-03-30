#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> left(n, -1); // index of the largest integer to the left of i
    if (n > 1) {
      left[1] = 0;
    }
    for (int i = 2; i < n; i++) {
      left[i] = left[i - 1];
      if (a[i - 1] > a[left[i - 1]]) {
        left[i] = i - 1;
      }
    }
    vector<int> right(n + 1, -1); // index of the rightmost integer that is less than or equal i
    for (int i = 0; i < n; i++) {
      right[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
      right[i] = max(right[i], right[i - 1]);
    }
    vector<int> dp(n, -1);
    auto recurse = [&](int i, int from, int fromfrom, auto recurse) -> int {
      if (dp[i] != -1) {
        return dp[i];
      }
      int value1 = left[i] < 0 || a[left[i]] < a[i] || i == fromfrom ? 0 : recurse(left[i], i, from, recurse);
      int value2 = right[a[i] - 1] <= i || i == fromfrom ? 0 : recurse(right[a[i] - 1], i, from, recurse);
      return dp[i] = max({a[i], value1, value2});
    };
    for (int i = 0; i < n; i++) {
      cout << recurse(i, -2, -3, recurse) << " \n"[i == n - 1];
    }
  }
  return 0;
}

/*
For each integer, the answer is either the maximum integer to the left of a[i] or the maximum integer that it can reach towards the right.

The first part is easy.

The second part, not so much.

We need to know the rightmost integer a[j] (j > i) that is less than a[i].

What we can do is to store r[i], the rightmost instance of integers less than or equal to i.

We first take g[i] which is the rightmost instance of integers equal to i.

Then, r[i] = max(r[i - 1], g[i]).

The answer for each i is dp[i] = max(dp[l[i]], dp[r[i]]).

What are the base cases?

The integers which do not have an integer towards left that is greater than it or an integer towards right that is less than.
*/
