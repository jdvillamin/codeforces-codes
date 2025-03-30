#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << "\n";
        return;
    }
    vector<ll> answer(n);
    for (ll i = 0; i < n; i++) {
        answer[2 * i % n] = i + 1;
    }
    for (ll i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
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
