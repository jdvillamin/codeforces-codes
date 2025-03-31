#include <bits/stdc++.h>

using namespace std;

vector<int> start = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 13, 13, 1, 12};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      for (int i = 1; i <= n / 2; i++) {
        cout << i << " " << i << " \n"[i == n / 2];
      }
      continue;
    }
    if (n < 27) {
      cout << -1 << "\n";
      continue;
    }
    for (int i : start) {
      cout << i << " ";
    }
    for (int i = 14; i <= n / 2; i++) {
      cout << i << " " << i << " ";
    }
    cout << "\n";
  }
  return 0;
}

/*
If n is even, then the answer can be 1 1 2 2 ... n/2 n/2.

What if n is odd?

We have some numbers that have even instance.

We also have some numbers that have odd instance.

Let's pick one with odd instance and pick the first three instances. Note that it can't be one.

Suppose their positions are i, j, k where i < j < k.

Thus, j - i = a^2 is a square, k - j = b^2 is a square, and k - i = c^2 is a square.

Thus, (a, b, c) form a pythagorean triple.

The smallest pythagorean triple is (3, 4, 5).

This means that n must be at least 25 + 1 = 26. Since n is odd, then n is at least 27.

We can have something like:

1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 13 13 1 12.
*/
