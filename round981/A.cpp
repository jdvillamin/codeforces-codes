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
		int x = 0, turn = -1, i = 1;
		while (abs(x) <= n) {
			x += turn * i;
			turn *= -1;
			i += 2;
		}
		cout << (turn == 1 ? "Sakurako" : "Kosuke") << "\n";
	}
	return 0;
}
