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
    vector<int> count(n, 0);
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      count[--h]++;
    }
    cout << n - *max_element(count.begin(), count.end()) << "\n";
  }
  return 0;
}

/*
Get the largest chain of integers that are non-decreasing.

Adjust the others in between.

That's for the general case.

However, it is given that h[i] >= h[i + 1].

This means that the largest chain of integers that are non-decreasing is an integer sequence whose elements are equal.
*/
