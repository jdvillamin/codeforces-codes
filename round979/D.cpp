#include <bits/stdc++.h>

using namespace std;

int log2_floor(int i) {
	return i ? __builtin_clz(1) - __builtin_clz(i) : -1;
}

vector<vector<int>> build_min(int n, int k, vector<int> &a) {
	vector<vector<int>> st(k + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++)
		st[0][i] = a[i];
	for (int i = 1; i <= k; i++)
		for (int j = 0; j + (1 << i) <= n; j++)
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	return st;
}

vector<vector<int>> build_max(int n, int k, vector<int> &a) {
	vector<vector<int>> st(k + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++)
		st[0][i] = a[i];
	for (int i = 1; i <= k; i++)
		for (int j = 0; j + (1 << i) <= n; j++)
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	return st;
}

int min_query(int l, int r, vector<vector<int>> &st) {
	int i = log2_floor(r - l + 1);
	return min(st[i][l], st[i][r - (1 << i) + 1]);
}

int max_query(int l, int r, vector<vector<int>> &st) {
	int i = log2_floor(r - l + 1);
	return max(st[i][l], st[i][r - (1 << i) + 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			p[i]--;
		}
		string s;
		cin >> s;
		// store independent subranges as start indices
		vector<int> starts = {0};
		for (int i = 0; i + 1 < n; i++)
			if (s.substr(i, 2) == "LR")
				starts.push_back(i + 1);
		set<pair<int, int>> subranges;
		int k = starts.size();
		for (int i = 0; i < k; i++)
			subranges.insert({starts[i], (i == k - 1) ? n - 1 : starts[i + 1] - 1});
		// check if each subrange can be sorted
		vector<vector<int>> st_min = build_min(n, 25, p), st_max = build_max(n, 25, p);
		auto is_good = [&](int a, int b) {
			return min_query(a, b, st_min) == a && max_query(a, b, st_max) == b;
		};
		int good_subranges = 0;
		for (int i = 0; i < k; i++) {
			int a = starts[i], b = (i == k - 1) ? n - 1 : starts[i + 1] - 1;
			if (is_good(a, b)) 
				good_subranges++;
		}
		while (q--) {
			int i;
			cin >> i;
			i--;	
			int a, b;
			// remove subranges near i before modification
			if (i > 0 && s.substr(i - 1, 2) == "LR") {
				auto subrange1 = prev(subranges.lower_bound({i - 1, n}));
				a = (*subrange1).first;
				if (is_good(a, i - 1))
					good_subranges--;
				subranges.erase(subrange1);
				auto subrange2 = prev(subranges.lower_bound({i, n}));
				b = (*subrange2).second;
				if (is_good(i, b))
					good_subranges--;
				subranges.erase(subrange2);
			} else if (i < n - 1 && s.substr(i, 2) == "LR") {
				auto subrange1 = prev(subranges.lower_bound({i, n}));
				a = (*subrange1).first;
				if (is_good(a, i))
					good_subranges--;
				subranges.erase(subrange1);
				auto subrange2 = prev(subranges.lower_bound({i + 1, n}));
				b = (*subrange2).second;
				if (is_good(i + 1, b))
					good_subranges--;
				subranges.erase(subrange2);
			} else {
				auto subrange = prev(subranges.lower_bound({i, n}));
				a = (*subrange).first, b = (*subrange).second;
				if (is_good(a, b))
					good_subranges--;
				subranges.erase(subrange);	
			}	
			// add subranges after modification
			s[i] = (s[i] == 'L') ? 'R' : 'L';
			if (i > 0 && s.substr(i - 1, 2) == "LR") {
				if (is_good(a, i - 1))
					good_subranges++;
				subranges.insert({a, i - 1});
				if (is_good(i, b))
					good_subranges++;
				subranges.insert({i, b});
			} else if (i < n - 1 && s.substr(i, 2) == "LR") {
				if (is_good(a, i))
					good_subranges++;
				subranges.insert({a, i});
				if (is_good(i + 1, b))
					good_subranges++;
				subranges.insert({i + 1, b});
			} else {
				if (is_good(a, b))
					good_subranges++;
				subranges.insert({a, b});	
			}
			cout << (good_subranges == (int) subranges.size() ? "YES" : "NO") << "\n";	
		}			
	}
	return 0;
}

/*
 * If there is an LR substring, then this causes "slicing" in a the permutation.
 *
 * This means that the sliced subranges must be independent of the other.
 *
 * Note that and subrange without an LR substring can be sorted since there are links in adjacent positions.
 *
 * Otherwise, we need to check if all numbers in the subrange belong to that subrange in the sorted order.
 *
 * Consider the subrange [a:b].
 *
 * A neat way to check if all integers within the subrange must be there is to check the minimum and maximum.
 *
 * If the minimum of that subrange is a and the maximum is b, then all integers must be in that subrange due to distinctness.
 *
 * We can use a range minimum data structures for this.
 */
