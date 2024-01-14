#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

const int N = 200000 + 228;
map <int, int> g[N];
vector <bool> used;

int dfs(int u, int xr){
    used[u] = 1;
    int res = 0;

    for (auto [v, w] : g[u]){
        if ((xr ^ w) && (!used[v])){
            res += dfs(v, xr ^ w) + 1;
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u][v] = w;
        g[v][u] = w;
    }

    for (int u = 0; u < n; u++){
        used.assign(n, 0);
        used[u] = 1;

        int res = 1;
        for (auto [v, w] : g[u]){
            if (w != 0){
                res += dfs(v, w) + 1;
            }
        }
        cout << res << " ";
    }
    

    return 0;
}