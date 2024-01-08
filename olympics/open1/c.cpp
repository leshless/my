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

void solve(){
    int n, m;
    cin >> n >> m;

    vector <int> deg(n, 0);    
    vector <int> g[n];

    while(m--){
        int u, v;
        cin >> u >> v;
        u--; v--;

        g[u].push_back(v);
        g[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }


    auto cmp = [](pair <int, int> p1, pair <int, int> p2){return p1.second < p2.second;};
    peque <pair <int, int>, vector <pair <int, int>>, decltype(cmp)> ord(cmp); 
    for (int i = 0; i < n; i++){
        ord.push({i, deg[i]});
    }

    set <int> real;
    while(!ord.empty()){
        auto p = ord.top();
        ord.pop();

        int u = p.first;
        int d = p.second;

        if (d == deg[u]){
            real.insert(d);
            for (int v : g[u]){
                if (deg[u] != deg[v]){
                    deg[v]--;
                }
            }
        }else{
            ord.push({u, deg[u]});
        }
    }

    // for (int d : real){
    //     cout << d << ' ';
    // }
    // cout << endl;

    cout << real.size() << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}
    