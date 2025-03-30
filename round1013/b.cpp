#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll greater = 0;
    for (ll y : a) {
        if (y >= x) {
            greater++;
        }
    }
    vector<ll> smaller;
    for (ll y : a) {
        if (y < x) {
            smaller.push_back(y);
        }
    }
    sort(smaller.begin(), smaller.end());
    ll extra_teams = 0;
    ll m = (ll) smaller.size();
    ll i = m - 1;
    while (i >= 0) {
        ll total = smaller[i];
        ll count = 1;
        while (total < x) {
            if (i == 0) {
                break;
            }
            i--;
            count++;
            total = count * smaller[i];
        }
        if (total < x) {
            break;
        }
        extra_teams++;
        i--;
    }
    cout << greater + extra_teams << "\n";
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
