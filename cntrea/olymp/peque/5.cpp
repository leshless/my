#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define peque priority_queue
#define map unordered_map

struct entry{
    int v;
    ll d;
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    auto cmp = [](entry e1, entry e2){return e1.d > e2.d;};
    peque <entry, vector <entry>, decltype(cmp)> pq(cmp);
    map <int, map <int, ll>> g;
    map <int, ll> dist;

    int v1, v2;
    ll w;
    while (cin >> v1 >> v2 >> w){
        if (g.count(v1) == 0){
            g[v1] = {};
        }
        if (g.count(v2) == 0){
            g[v2] = {};
        }

        g[v1][v2] = w;
        g[v2][v1] = w;
    }

    pq.push({0, 0});

    while (!pq.empty()){
        int v = pq.top().v;
        int d = pq.top().d;
        pq.pop();

        if (dist.count(v) == 0){
            dist[v] = d; 
            for (auto [nb, w] : g[v]){
                pq.push({nb, d + w});
            }
        }
    }

    if (dist.count(1)){
        cout << dist[1] << endl;
    }else{
        cout << -1 << endl;
    }
    

    

    return 0;
}