#include <bits/stdc++.h>

using namespace std;

string vowels = "aeiou";

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int q = n / 5, r = n % 5;
		string ans = "";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < q; j++) {
				ans += vowels[i];
			}
			if (r > 0) {
				ans += vowels[i];
				r--;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
