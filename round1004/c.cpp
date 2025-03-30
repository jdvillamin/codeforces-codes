#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll power = 1, sum = 0;
    auto has_7 = [&](ll x) -> bool {
        while (x) {
            if (x % 10 == 7) {
                return true;
            }
            x /= 10;
        }
        return false;
    };
    ll answer = 100;
    for (ll i = 0; i < 18; i++) {
        sum += power * 9;
        power *= 10;
        ll n_copy = n;
        for (ll times = 0; times < 10; times++) {
            if (has_7(n_copy)) {
                answer = min(answer, times);
            }
            n_copy += sum;
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
