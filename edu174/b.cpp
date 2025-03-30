#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, -1, 1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> count(n * m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            count[a[i][j]] = 1;
        }
    }
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && a[i][j] == a[i + 1][j]) {
                count[a[i][j]] = 2;
            } else if (j + 1 < m && a[i][j] == a[i][j + 1]) {
                count[a[i][j]] = 2;
            }
            max_count = max(max_count, count[a[i][j]]);
        }
    }
    int answer = 0;
    for (int i = 1; i <= n * m; i++) {
        answer += count[i];
    }
    answer -= max_count;
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
