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
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			p[i]--;
		}
		int ans = 0;
		vector<bool> visited(n, false);
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				int current = p[i], count = 0;
				while (current != i) {
					visited[current] = true;
					count++;
					current = p[current];
				}
				ans += count / 2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
