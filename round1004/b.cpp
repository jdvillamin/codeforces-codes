#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    string answer = "Yes";
    vector<int> bag2;
    for (int i = 0; i < n; i += 2) {
        sort(bag2.begin(), bag2.end());
        int j = 0;
        while (j < (int) bag2.size() && bag2[j] <= a[i]) {
            if (bag2[j] == a[i]) {
                a[i]++;
            }
            j++;
        }
        if (a[i] < a[i + 1]) {
            answer = "No";
            break;
        }
        bag2.push_back(a[i]);
    }
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
