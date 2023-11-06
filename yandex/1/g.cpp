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
vector <int> weight;
vector <bool> used;
vector <int> ord;

ll dfs(int u){
    used[u] = 1;

    ll res = weight[u];
    for (int v : g[u]){
        if (!used[v]){
            res += dfs(v);
        }
    }

    ord.push_back(u);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    g.resize(n);
    weight.resize(n);
    used.assign(n, 0);

    for (int i = 0; i < n; i++){
        cin >> weight[i];
    }

    for (int u = 0; u < n; u++){
        int m;
        cin >> m;
        while (m--){
            int v;
            cin >> v;
            v--;
            g[u].push_back(v);
        }
    }

    ll res = dfs(0);

    cout << res << " " << ord.size() << endl;
    for (int u : ord){
        cout << u+1 << " ";
    }
    cout << endl;


    return 0;
}   