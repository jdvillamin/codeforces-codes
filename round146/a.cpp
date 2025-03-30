#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll answer = (n - 1) * (n - 2) * (n - 3);
    for (ll i = max(1LL, n - 6); i <= n; i++) {
        for (ll j = i; j <= n; j++) {
            answer = max(answer, lcm(lcm(n, i), j));
        }
    }
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
