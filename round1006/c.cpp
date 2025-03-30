#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;
    ll x_copy = x, b = 0;
    while (x_copy) {
        if ((x_copy & 1) == 0) {
            break;
        }
        x_copy >>= 1;
        b++;
    }
    ll r = (1LL << b) - 1;
    if (r <= n - 2) {
        for (ll i = 0; i <= r; i++) {
            cout << i << " ";
        }
        for (ll i = 0; i < n - (r + 1); i++) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        ll current_or = 0;
        for (ll i = 0; i <= n - 1; i++) {
            current_or |= i;
        }
        if (current_or != x) {
            for (ll i = 0; i <= n - 2; i++) {
                cout << i << " ";
            }
            cout << x << "\n";
        } else {
            for (ll i = 0; i <= n - 1; i++) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
