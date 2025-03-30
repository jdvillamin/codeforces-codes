#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<vector<char>> g(n, vector<char>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(2, 0)));
    vector<vector<vector<ll>>> pr(n, vector<vector<ll>>(m, vector<ll>(2, 0)));
    auto range_sum = [&](ll i, ll j1, ll j2, ll k) -> ll {
        return pr[i][min(m - 1, j2)][k] - (j1 > 0 ? pr[i][j1 - 1][k] : 0);
    };
    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = 0; j < m; j++) {
            if (g[i][j] == 'X') {
                if (i == n - 1) {
                    dp[i][j][0] = 1;
                    continue;
                }
                dp[i][j][0] += range_sum(i + 1, j - d + 1, j + d - 1, 0);
                dp[i][j][0] += range_sum(i + 1, j - d + 1, j + d - 1, 1);
                dp[i][j][0] %= MOD;
            }
        }
        for (ll j = 0; j < m; j++) {
            pr[i][j][0] = (j > 0 ? pr[i][j - 1][0] : 0) + dp[i][j][0];
            pr[i][j][0] %= MOD;
        }
        for (ll j = 0; j < m; j++) {
            if (g[i][j] == 'X') {
                dp[i][j][1] += range_sum(i, j - d, j + d, 0) - dp[i][j][0];
                dp[i][j][0] %= MOD;
            }
        }
        for (ll j = 0; j < m; j++) {
            pr[i][j][1] = (j > 0 ? pr[i][j - 1][1] : 0) + dp[i][j][1];
            pr[i][j][1] %= MOD;
        }
    }
    cout << ((pr[0][m - 1][0] + pr[0][m - 1][1]) % MOD + MOD) % MOD << "\n";
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
