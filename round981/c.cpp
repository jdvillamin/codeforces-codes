#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int l = (n - 1) / 2 - 1, r = n / 2 + 1, ans = !(n & 1) && a[l + 1] == a[r - 1] ? 1 : 0;
		while (l >= 0 && r < n) {
			ans += min((a[l] == a[l + 1]) + (a[r - 1] == a[r]), (a[r] == a[l + 1]) + (a[r - 1] == a[l]));
			l--;
			r++;
		}
		cout << ans << "\n";
	}
	return 0;
}
