#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1;
    ll r = m - 1;
    ll answer = m;
    auto test_length = [&](ll l) -> bool {
        ll quotient = m / (l + 1);
        ll remainder = m % (l + 1);
        ll row_seats = quotient * l + remainder;
        return row_seats * n >= k;
    };
    while (l <= r) {
        ll bench_length = (l + r) / 2;
        if (test_length(bench_length)) {
            answer = min(answer, bench_length);
            r = bench_length - 1;
        } else {
            l = bench_length + 1;
        }
    }
    cout << answer << "\n";
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
