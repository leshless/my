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
vector <map<int, bool>> cld;
vector <ll> res;
vector <int> cnt;
vector <bool> used;

void dfs1 (int u){
    used[u] = 1;

    for (auto [v, w] : g[u]){
        if (!used[v]){
            dfs1(v);
            cnt[u] += cnt[v];
            cld[u].insert(cld[v].begin(), cld[v].end());
        }
    }

    cnt[u]++;
    cld[u][u] = 1;
}

void dfs2 (int u){
    used[u] = 1;

    for (auto [v, w] : g[u]){
        if (!used[v]){
            if (cnt[v] != 1){
                dfs2(v);
            }

            for (int i = 0; i < n; i++){
                if (cld[v][i]){
                    res[i] += ll(w) * (n - cnt[v]);
                }else{
                    res[i] += ll(w) * cnt[v];
                }
            }

        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    g.resize(n);
    cld.resize(n);
    res.resize(n);
    used.assign(n, 0);
    cnt.assign(n, 0);

    for (int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        g[u][v] = w;
        g[v][u] = w;
    }

    dfs1(n-1);
    used.assign(n, 0);
    dfs2(n-1);
    
    for (int i = 0; i < n; i++){
        cout << res[i] << " ";
    }



    return 0;
}