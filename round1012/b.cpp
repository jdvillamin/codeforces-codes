#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (g[i][j] == '1') {
                bool left = true, top = true;
                for (ll k = 0; k < j; k++) {
                    if (g[i][k] == '0') {
                        left = false;
                    }
                }
                for (ll k = 0; k < i; k++) {
                    if (g[k][j] == '0') {
                        top = false;
                    }
                }
                if (!left && !top) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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
