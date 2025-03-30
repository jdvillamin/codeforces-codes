#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll binary_power(ll b, ll e) {
    ll result = 1;
    while (e) {
        if (e & 1) {
            result = result * b % MOD;
        }
        b = b * b % MOD;
        e >>= 1;
    }
    return result;
}

ll mod_inverse(ll a) {
    return binary_power(a, MOD - 2);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> prefix_2(n), suffix_3(n);
    prefix_2[0] = (a[0] == 2 ? 1 : 0);
    for (ll i = 1; i < n; i++) {
        prefix_2[i] = prefix_2[i - 1] + (a[i] == 2 ? 1 : 0);
    }
    suffix_3[n - 1] = (a[n - 1] == 3 ? 1 : 0);
    for (ll i = n - 2; i >= 0; i--) {
        suffix_3[i] = suffix_3[i + 1] + (a[i] == 3 ? 1 : 0);
    }
    vector<ll> suffix_ways(n);
    for (ll i = 0; i < n; i++) {
        if (a[i] == 3) {
            suffix_ways[i] = binary_power(2LL, prefix_2[i]);
        }
    }
    for (ll i = n - 2; i >= 0; i--) {
        suffix_ways[i] = (suffix_ways[i] + suffix_ways[i + 1]) % MOD;
    }
    ll answer = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 1) {
            ll inverse = mod_inverse(binary_power(2LL, prefix_2[i]));
            ll add = ((inverse * suffix_ways[i] - suffix_3[i]) % MOD + MOD) % MOD;
            answer = (answer + add) % MOD;
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
