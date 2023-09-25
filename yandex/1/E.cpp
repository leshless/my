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

int n;
vector <map<int, int>> g;
vector <int> cld;
vector <bool> used;

void dfs1 (int u){
    used[u] = 1;
    int s = 0;

    for (auto [v, w] : g[u]){
        if (!used[v]){
            dfs1(v);
            s += cld[v];
        }
    }

    cld[u] = s + 1;
}

ll dfs2 (int u){
    used[u] = 1;
    ll res = 0;

    for (auto [v, w] : g[u]){
        if (!used[v]){
            if (cld[v] != 1){
                res += dfs2(v);
            }
            res += ll(w) * cld[v] * (n - cld[v]);
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    map <int, int> nbs;
    g.assign(n, nbs);
    used.assign(n, 0);
    cld.assign(n, 0);

    for (int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        g[u][v] = w;
        g[v][u] = w;
    }

    dfs1(0);
    used.assign(n, 0);
    ll res = dfs2(0) * 2;
    
    cout << res << endl;



    return 0;
}