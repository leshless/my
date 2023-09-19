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

  vector <int> ord(n);
  for (int i = 0; i < n; i++){
    cin >> ord[i];
    ord[i]--;
  }

  reverse(ord.begin(), ord.end());

  for (int i = 0; i < n; i++){
    int u = ord[i];

    if (deg[u]){
      cout << "NO" << endl;
      return 0;
    }

    for (auto v : rev[u]){
      deg[v]--;
    }
  }

  cout << "YES" << endl;

  return 0;
}
