#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll k;
    cin >> k;
    ll x = 0, y = 0;
    vector<pair<ll, ll>> points;
    points.push_back(make_pair(x, y));
    bool right = true;
    ll k_copy = k;
    while (k_copy) {
        ll l = 2, r = 500;
        ll answer = 2;
        while (l <= r) {
            ll m = (l + r) / 2;
            if (m * (m - 1) / 2 <= k_copy) {
                answer = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        k_copy -= answer * (answer - 1) / 2;
        for (ll i = 1; i < answer; i++) {
            if (right) {
                x++;
            } else {
                y++;
            }
            points.push_back(make_pair(x, y));
        }
        right = !right;
    }
    cout << (ll) points.size() << "\n";
    for (auto &p : points) {
        cout << p.first << " " << p.second << "\n";
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
