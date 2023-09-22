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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;

    vector <map<int,int>> g(n);

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        g[u][v] = w;
    }

    vector <int> dst(n, 0x7fffffff);
    dst[s] = 0;

    for (int i = 0; i < n; i++){
        for (int u = 0; u < n; u++){
            for (auto [v, w] : g[u]){
                if (dst[u] < 0x7fffffff){
                    dst[v] = min(dst[v], dst[u] + w);
                }
            }
        }
    }

    if (dst[t] != 0x7fffffff){
        cout << dst[t] << endl;
    }else{
        cout << "Unreachable" << endl;  
    }



    return 0;
}