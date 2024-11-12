#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string ans = "NO";
		if (s[0] == '1' || s[n - 1] == '1') 
			ans = "YES";
		for (int i = 0; i + 1 < n; i++)
			if (s.substr(i, 2) == "11")
				ans = "YES";
		cout << ans << "\n";
	}
	return 0;
}

/*
 * Let's look at sample cases.
 *
 * 11
 *
 * Alice places one AND or OR and she wins because 1 AND 1 = 1 OR 1 = 1.
 *
 * 010
 *
 * Alice must place an OR between a 0 and 1. Giving either 01 or 10. However, Bob can simply use AND and get 0.
 *
 * Since OR will be evaluated first, an observation is that when a 1 exists as the first or last boolean, Alice wins.
 *
 * Furthermore, if there exists a 11 substring, then Alice will win.
 *
 * Otherwise, we know that all 1's have 0's beside them.
 *
 * There's no point for Alice to put OR on two 0's.
 *
 * Thus, the only option is to put OR on a 01 or 10.
 *
 * However, if Alice does so, Bob can simply place and AND on the other side since a 1 will be between two 0's.
 *
 * 0 OR 10 -> 0 OR 1 AND 0 which will evaluate to 0 OR (1 AND 0) = 0 OR 0 = 0.
 *
 * Thus, there's no win for Alice in this scenario.
 */
