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
vector <ll> res;
vector <int> cld;
vector <bool> used;

void dfs1 (int u){
    used[u] = 1;

    for (auto [v, w] : g[u]){
        if (!used[v]){
            dfs1(v);
            cld[u] += cld[v];
        }
    }

    cld[u]++;
    return;
}

void dfs2 (int u){
    used[u] = 1;

    for (auto [v, w] : g[u]){
        if (!used[v]){
            dfs2(v);
            res[u] += res[v] + ll(w) * cld[v];
        }
    }

    return;
}

void dfs3 (int u){
    used[u] = 1;

    for (auto [v, w] : g[u]){
        if (!used[v]){
            res[v] += res[u] - (res[v] + ll(w) * cld[v]) + ll(w) * (n - cld[v]);
            dfs3(v);
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    g.resize(n);
    cld.assign(n, 0);
    res.assign(n, 0);
    used.assign(n, 0);

    for (int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        g[u][v] = w;
        g[v][u] = w;
    }

    dfs1(0);
    used.assign(n, 0);
    dfs2(0);
    used.assign(n, 0);
    dfs3(0);
    
    for (int i = 0; i < n; i++){
        cout << res[i] << " ";
    }

    return 0;
}