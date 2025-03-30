#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> digits = {0, 1, 2, 3, 5};
vector<int> counts = {3, 1, 2, 1, 1};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    int answer = 0;
    for (int x : a) {
        answer++;
        mp[x]++;
        bool complete = true;
        for (int i = 0; i < 5; i++) {
            if (mp[digits[i]] < counts[i]) {
                complete = false;
            }
        }
        if (complete) {
            cout << answer << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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
