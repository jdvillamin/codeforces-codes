#include <bits/stdc++.h>

using namespace std;

int t, i, n, x, mn, mx;

int main() {
	scanf("%d", &t);
	while (t--) {
		mn = 1000;
		mx = 1;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &x);
			mn = min(mn, x);
			mx = max(mx, x);
		}
		printf("%d\n", (n - 1) * (mx - mn));
	}
	return 0;
}

/*
 * What if we place the minimum at the first position?
 *
 * Also, what if we place the maximum at the second position?
 *
 * If n = 1, the answer is 0.
 *
 * Otherwise, what is the answer?
 *
 * c[1] - b[1] is always 0.
 *
 * c[i] - b[i] for all i >= 2 can be x = (max[1 <= i <= n] a[i]) - (min[1 <= i <= n] a[i]).
 *
 * Thus, the answer is 0 + (n - 1) * x = (n - 1) * x.
 */
