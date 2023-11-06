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

const int N = 1e5 + 228;
unordered_map <int, ll> g[N];
unordered_map <int, ll> dst;

ll dfs(int u, int t) {
  if (u == t) {
    return 0;
  }

  ll res = LLONG_MAX;
  for (auto[v, w] : g[u]) {
    ll l;
    if (dst.count(v) != 0){
        l = dst[v];
    }else{
        l = dfs(v, t);
    }

    if (l != LLONG_MAX) {
      res = min(res, l + w);
    }
  }

  dst[u] = res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;
  t--;

  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;
    
    if (g[u].count(v) != 0){
        g[u][v] = min(g[u][v], w);
    }else{
        g[u][v] = w;
    }
  }

  ll res = dfs(s, t);

  if (res == LLONG_MAX) {
    cout << "Unreachable" << endl;
  } else {
    cout << res << endl;
  }

  return 0;
}