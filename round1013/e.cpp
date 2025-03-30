#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 10000000;

vector<ll> primes;

void solve() {
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        ll l = 0;
        ll r = (ll) primes.size() - 1;
        ll answer = 0;
        while (l <= r) {
            ll m = (l + r) / 2;
            if (i * primes[m] <= n) {
                answer = m + 1;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        sum += answer;
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> is_prime(N + 1, true);
    for (ll i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
