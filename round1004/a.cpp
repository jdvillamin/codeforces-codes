#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x + 1 == y || x > y && ((y - x) % 9 + 9) % 9 == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
