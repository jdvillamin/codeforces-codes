#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> p(n), s(n);
    // greedily compute p[i]
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        p[i] = p[i - 1];
      }
      sum += a[i];
      if (sum >= v) {
        p[i]++;
        sum = 0;
      }
    }
    // greedily compute s[i]
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (i + 1 < n) {
        s[i] = s[i + 1];
      }
      sum += a[i];
      if (sum >= v) {
        s[i]++;
        sum = 0;
      }
    }
    // rightmost suffix that can feed i monsters
    vector<int> shortest_suffix(n + 1, -1);
    for (int i = 0; i < n; i++) {
      shortest_suffix[s[i]] = i;
    }
    shortest_suffix[0] = n;
    // prefix sum to compute subarray sum
    vector<ll> prefix_sum(n);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
      prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    auto subarray_sum = [&](int l, int r) -> ll {
      if (l - r == 1) {
        return 0;
      }
      if (l > r) {
        return -1;
      }
      return l == 0 ? prefix_sum[r] : prefix_sum[r] - prefix_sum[l - 1];
    };
    // fix the number of pieces for the prefix
    ll answer = shortest_suffix[m] != -1 ? subarray_sum(0, shortest_suffix[m] - 1) : -1;
    for (int i = 0; i < n; i++) {
      if (m >= p[i] && shortest_suffix[m - p[i]] != -1) { 
        answer = max(answer, subarray_sum(i + 1, shortest_suffix[m - p[i]] - 1));  
      }
    }
    cout << answer << "\n";
  }
}
