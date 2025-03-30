#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<ll> pq;
    ll increase = 0, answer = n;
    for (ll i = 0; i < n; i++) {
        if (a[i] < 0) {
            pq.push(-a[i]);
        }
        a[i] += (i > 0 ? a[i - 1] : 0);
        while (a[i] + increase < 0) {
            increase += pq.top();
            pq.pop();
            answer--;
        }
    }
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
It is clearly better to include all positive potions.

Now, the problem becomes, choosing the negative potions that we can include so that all prefix sums of the potions will be non-negative.

Is there a greedy solution?

Another idea: what if we get the accumulations of the array and assume that we picked all potions throughout.

Suppose we have these accumulations as b[1], b[2], ..., b[n].

Consider i to be the leftmost index such that b[i] is negative.

Then, it is required to increase b[i] to be non-negative.

The best way is the unpick the negative potions with the highest magnitudes until b[i] becomes non-negative.

This also increases b[j] for all j > i.

We do this until all b[i] is non-negative.

There is an overkill solution where we can use segment trees to update b[j] for all j > i.

However, we can also simply keep track of the accumulated negative potions we removed.

Now, how do we choose the negative potions?

We can simply maintain a sorted container, perhaps using a multiset or a priority queue.
*/
