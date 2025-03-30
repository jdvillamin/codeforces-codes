#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;
    x--;
    ll degree_x = 0;
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u == x || v == x) {
            degree_x++;
        }
    }
    if (degree_x < 2) {
        cout << "Ayush\n";
        return;
    }
    cout << ((n & 1) ? "Ashish" : "Ayush") << "\n";
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
