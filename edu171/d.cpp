#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> h(n + 2, 0); // h[i] = s(i, i) + s(i, i + 1) + ... + s(i, n)
    for (ll i = n; i >= 1; i--) {
        h[i] = (n - (i - 1)) * a[i] + h[i + 1];
    }
    vector<ll> ph(n + 1, 0); // ph[i] = h[1] + h[2] + ... + h[i]
    for (ll i = 1; i <= n; i++) {
        ph[i] = ph[i - 1] + h[i];
    }
    vector<ll> pwa(n + 1, 0); // pwa[i] = n * a[1] + (n - 1) * a[2] + ... + (n - (i - 1)) * a[i]
    for (ll i = 1; i <= n; i++) {
        pwa[i] = pwa[i - 1] + (n - (i - 1)) * a[i];
    }
    vector<ll> pa(n + 1, 0); // pa[i] = a[1] + a[2] + ... + a[i]
    for (ll i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + a[i];
    }
    vector<ll> ppa(n + 1, 0); // ppa[i] = pa[1] + pa[2] + ... + pa[i]
    for (ll i = 1; i <= n; i++) {
        ppa[i] = ppa[i - 1] + pa[i];
    }
    auto psi = [&](ll i, ll r) -> ll { // psi(i, r) = s(i, i) + s(i, i + 1) + ... + s(i, r)
        return h[1] - (pwa[i - 1]) - (ppa[n] - ppa[r]) + pa[i - 1] * (n - r);
    };
    auto range_si = [&](ll i, ll l, ll r) -> ll { // range_si = s(i, l) + s(i, l + 1) + ... + s(i, r)
        return psi(i, r) - psi(i, l - 1);
    };
    // i'm too lazy to use formulas to calculate where l and r belong to :P
    vector<ll> blocks(n + 1);
    for (ll i = 1; i <= n; i++) {
        blocks[i] = blocks[i - 1] + (n - (i - 1));
    }
    auto get_block = [&](ll x) -> ll {
        ll l = 1, r = n, result = 1;
        while (l <= r) {
            ll m = (l + r) / 2;
            if (x <= blocks[m]) {
                result = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return result;
    };
    ll q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll l_block = get_block(l);
        ll r_block = get_block(r);
        ll ll_block = l - blocks[l_block - 1] + l_block - 1; // left index of the leftmost block
        ll rr_block = r - blocks[r_block - 1] + r_block - 1; // right index of the rightmost block
        if (l_block == r_block) { // [l, r] is inside a single block
            cout << range_si(l_block, ll_block, rr_block) << "\n";
        } else { // [l, r] spans multiple blocks
            ll l_range_sum = range_si(l_block, ll_block, n);
            ll m_range_sum = ph[r_block - 1] - ph[l_block];
            ll r_range_sum = range_si(r_block, r_block, rr_block);
            cout << l_range_sum + m_range_sum + r_range_sum << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
