#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j] == 'N') y++;
            if (s[j] == 'E') x++;
            if (s[j] == 'S') y--;
            if (s[j] == 'W') x--;
            if (x == a && y == b) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
