#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll j = 0; j < m; j++) {
        cin >> b[j];
    }
    if (n == 1) {
        for (ll j = 0; j < m; j++) {
            cout << a[0] + b[j] << " ";
        }
        cout << "\n";
        return;
    }
    swap(a[0], *min_element(a.begin(), a.end()));
    for (ll i = 1; i < n; i++) {
        a[i] -= a[0];
    }
    ll g = a[1];
    for (ll i = 2; i < n; i++) {
        g = __gcd(g, a[i]);
    }
    for (ll j = 0; j < m; j++) {
        cout << __gcd(a[0] + b[j], g) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
Note that gcd(x, y) = gcd(x, y - x).

The problem with getting g = gcd(a[1] + b[j], a[2] + b[j], ..., a[n] + b[j])
is that we need to get the gcd of n elements for each j.

However, note that g = gcd(a[1] + b[j], a[2] - a[1], ..., a[n] - a[1]).

g = gcd(a[1] + b[j], gcd(a[2] - a[1], ..., a[n] - a[1])).

We only need to compute g' = gcd(a[2] - a[1], ..., a[n] - a[1]) once and 
compute gcd(a[1] + b[j], g') for all j.
*/