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
    string answer = "YES";
    vector<bool> visited(n, false);
    for (int i = 0; answer == "YES" && i < n; i++) {
      if (!visited[i]) {
        vector<int> cycle;
        int current = i;
        while (!visited[current]) {
          visited[current] = true;
          cycle.push_back(current);
          current = p[current];
          if (abs(current - p[current]) > 1) {
            answer = "NO";
            break;
          }
        }
        sort(cycle.begin(), cycle.end());
      }
    }
    cout << answer << "\n";
  }
  return 0;
}

/*
Think about the implicit graph of nodes from 1 to n with edges (p[i], p[p[i]]).

Note that the degrees of each number is at most 2: 1 in degree and 1 out degree.

Consider the connected components. These are cycles.

If it is a loop, then we are done.

Otherwise, we need to check something.

What is that something?

Note that each element of the connected component are misplaced.

We sort the elements in the connected component. Note that they must be increasing.

If not, then the implicit graph defined by those elements whose edges are (x - 1, x), then we cannot swap.
*/
