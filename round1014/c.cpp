#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll same_parity = true;
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 != a[0] % 2) {
            same_parity = false;
            break;
        }
    }
    if (same_parity) {
        cout << *max_element(a.begin(), a.end()) << "\n";
        return;
    }
    ll odd_sum = 0, even_sum = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] & 1) {
            odd_sum += (a[i] + 1) / 2;
            even_sum += a[i] / 2;
        } else {
            odd_sum += a[i] / 2;
            even_sum += a[i] / 2;
        }
    }
    if (odd_sum == even_sum) {
        cout << odd_sum + even_sum << "\n";
    } else {
        cout << 2 * min(odd_sum, even_sum) + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
