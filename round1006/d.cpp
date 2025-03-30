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
    ll l = 1, r = 1;
    ll max_decrease = 0;
    for (ll i = 0; i < n; i++) {
        ll less = 0, more = 0;
        for (ll j = i; j < n; j++) {
            if (a[i] < a[j]) {
                less++;
            } else if (a[i] > a[j]) {
                more++;
            }    
            if (max_decrease < more - less) {
                max_decrease = more - less;
                l = i + 1;
                r = j + 1;
            }
        }
    }
    cout << l << " " << r << "\n";
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
