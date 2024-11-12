#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		int ans = 0;
		for (int row = 0; row < n; row++) {
			int i = row, j = 0, mn = INF;
			while (i < n && j < n) {
				mn = min(mn, a[i][j]);
				i++;
				j++;
			}
			if (mn < 0)
				ans -= mn;
		}
		for (int col = 1; col < n; col++) {
			int i = 0, j = col, mn = INF;
			while (i < n && j < n) {
				mn = min(mn, a[i][j]);
				i++;
				j++;
			}
			if (mn < 0)
				ans -= mn;
		}
		cout << ans << "\n";
	}
	return 0;
}
