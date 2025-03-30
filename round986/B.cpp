#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n, b, c;
        cin >> n >> b >> c;
        if (b == 0) {
            if (c >= n) {
                cout << n << "\n";
            } else if (c <= n - 3) {
                cout << -1 << "\n";
            } else {
                cout << n - 1 << "\n";
            }
            continue;
        }
        // b * (i - 1) + c <= n - 1
        // b * (i - 1) <= n - 1 - c
        // i - 1 <= (n - 1 - c) / b = (n - 1 - c) / b
        // i <= (n - 1 - c) / b + 1
        if (c > n - 1) {
            cout << n << "\n";
            continue;
        }
        long long max_i = (n - 1 - c) / b + 1;
        cout << n - max_i << "\n";
    }
}
