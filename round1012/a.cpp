#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll x, y, a;
    cin >> x >> y >> a;
    ll remainder = a % (x + y);
    if (remainder < x) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
