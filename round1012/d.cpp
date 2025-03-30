#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    if (n == 2) {
        cout << "2 1\n";
        return;
    }
    ll p = 0;
    for (ll i = n / 3 + 1; i <= 2 * (n / 3); i++) {
        bool is_prime = true;
        for (ll d = 2; d * d <= i; d++) {
            if (i % d == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            p = i;
            break;
        }
    }
    vector<ll> answer;
    answer.push_back(p);
    for (ll i = 1; i <= n / 3; i++) {
        answer.push_back(p - i);
        answer.push_back(p + i);
    }
    for (ll i = 1; i < p - n / 3; i++) {
        answer.push_back(i);
    }
    for (ll i = p + n / 3 + 1; i <= n; i++) {
        answer.push_back(i);
    }
    assert((ll) answer.size() == n);
    for (ll i : answer) {
        cout << i << " ";
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
