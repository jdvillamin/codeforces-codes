#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> t(n);
    for (ll i = 0; i < n; i++) {
        cin >> t[i];
    }
    set<vector<ll>> unoccupied, occupied;
    auto remove_cell = [&](ll x, ll y) -> void {
        if (x % 3 == 1 && y % 3 == 1) {
            unoccupied.erase({x + y, x, y});
            unoccupied.insert({x + y + 3, x + 3, y});
            unoccupied.insert({x + y + 3, x, y + 3});
            return;
        }
        if (x % 3 == 2 && y % 3 == 2) {
            occupied.erase({x + y + 2, x, y});
            occupied.insert({x + y + 5, x + 3, y});
            occupied.insert({x + y + 5, x, y + 3});
            return;
        }
        occupied.erase({x + y, x, y});
        occupied.insert({x + y + 3, x + 3, y});
        occupied.insert({x + y + 3, x, y + 3});
    };
    unoccupied.insert({2, 1, 1});
    occupied.insert({3, 1, 2});
    occupied.insert({3, 2, 1});
    occupied.insert({6, 2, 2});
    for (ll i = 0; i < n; i++) {
        ll x = 0, y = 0;
        if (t[i]) {
            vector<ll> v1 = *unoccupied.begin(), v2 = *occupied.begin();
            if (v1 < v2) {
                x = v1[1], y = v1[2];
            } else {
                x = v2[1], y = v2[2];
            }
        } else {
            vector<ll> v = *unoccupied.begin();
            x = v[1], y = v[2];
        }
        cout << x << " " << y << "\n";
        remove_cell(x, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
