#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll x, y;
    cin >> x >> y;
    if (x < y) {
        swap(x, y);
    }
    ll p = 1;
    for (ll i = 0; i < 40; i++) {
        p <<= 1;
    }
    if (x == y) {
        cout << -1 << "\n";
        return;
    }
    ll k = p - x;
    assert((x + k) + (y + k) == (x + k) ^ (y + k));
    cout << k << "\n";
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
