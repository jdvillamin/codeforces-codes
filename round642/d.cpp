#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Compare {
public:
    bool operator() (pair<ll, ll> a, pair<ll, ll> b) {
        ll a_length = a.second - a.first + 1;
        ll b_length = b.second - b.first + 1;
        if (a_length == b_length) {
            return a.first > b.first;
        }
        return a_length < b_length;
    };
};

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> pq;
    pq.push(make_pair(0, n - 1));
    for (ll i = 0; i < n; i++) {
        auto [l, r] = pq.top();
        pq.pop();
        ll m = (l + r) / 2;
        a[m] = i + 1;
        ll l1 = l, r1 = m - 1;
        ll l2 = m + 1, r2 = r;
        if (r1 - l1 + 1 > 0) {
            pq.push(make_pair(l1, r1));
        }
        if (r2 - l2 + 1 > 0) {
            pq.push(make_pair(l2, r2));
        }
    }
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
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
