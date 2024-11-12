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
		int ans = 0;
		long long current = 0;
		set<long long> prefix = {0};
		for (int i = 0; i < n; i++) {
			current += a[i];
			if (prefix.find(current) != prefix.end()) {
				ans++;
				current = 0;
				prefix.clear();
				prefix.insert(0);
				continue;
			}
			prefix.insert(current);
		}
		cout << ans << "\n";
	}
	return 0;
}
