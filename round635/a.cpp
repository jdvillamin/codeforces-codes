#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> nodes;
    auto dfs = [&](ll u, ll from, ll depth, auto dfs) -> ll {
        ll subtree_size = 1;
        for (ll v : adj[u]) {
            if (v != from) {
                subtree_size += dfs(v, u, depth + 1, dfs);
            }
        }
        nodes.push_back(depth - subtree_size + 1);
        return subtree_size;
    };
    dfs(0, -1, 0, dfs);
    sort(nodes.rbegin(), nodes.rend());
    cout << accumulate(nodes.begin(), nodes.begin() + k, 0LL) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
Suppose a node is part of the k chosen nodes.

Then, it is optimal that all nodes in its subtree are also chosen.

Proof: Suppose node u is chosen while some v, descendant of u, is not chosen.

If we choose v instead and unchoose u, 
then the contribution of the subtree of v does not change.

However, we may add more contributions for the other nodes 
in the subtree of u that are not part of the subtree of v.

This is because v is not chosen anymore.

The answer is therefore the sum of the k highest depth[v] - (subtree_size[v] - 1).
*/
