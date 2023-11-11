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

vector <vector<int>> g;
vector <vector<int>> gr;
vector <bool> used;
vector <int> ord;

void dfs(int u){
    if (used[u]){
        return;
    }
    used[u] = 1;

    for (int v : g[u]){
        dfs(v);
    }
    ord.push_back(u);
}

void find(int u){
    if (used[u]){
        return;
    }
    used[u] = 1;

    for (int v : gr[u]){
        find(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> nbs;
    g.assign(n, nbs);
    gr.assign(n, nbs);
    used.assign(n, 0);

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;

        if (u != v){
          g[u].push_back(v);
          gr[v].push_back(u);
        }
    }

    for (int i = 0; i < n; i++){
        dfs(i);
    }

    reverse(ord.begin(), ord.end());
    used.assign(n, 0);

    int res = 0;

    for (int i = 0; i < n; i++){
        int u = ord[i];
        if (!used[u]){
          find(u);
          res++;
        }
    }

    cout << res << endl;

    return 0;
}