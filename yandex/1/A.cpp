#pragma GCC optimize("O3")

#include <ext/pb_ds/assoc_container.hpp>

#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using dbl = double;
using ldbl = long double;
using uint = unsigned int;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector < int > deg;
  vector < vector < int >> rev;
  for (int i = 0; i < n; i++) {
    vector < int > u;
    rev.push_back(u);
    deg.push_back(0);
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    rev[v].push_back(u);
    deg[u]++;
  }

  stack < int > ord;
  for (int i = 0; i < n; i++) {
    if (!deg[i]) {
      ord.push(i);
    }
  }

  vector < int > res;
  while (!ord.empty()) {
    int u = ord.top();
    ord.pop();
    res.push_back(u);

    for (int v : rev[u]) {
      deg[v]--;
      if (!deg[v]) {
        ord.push(v);
      }
    }
  }

  reverse(res.begin(), res.end());
  if (int(res.size()) < n) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << res[i] + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}
