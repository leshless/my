#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> c(n);
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    vector <int> l(m);
    vector <int> d(m);
    vector <int> k(m);
    for (int i = 0; i < m; i++){
        cin >> l[i];
        k[i] = i;
    }
    for (int i = 0; i < m; i++){
        cin >> d[i];
        k[i] = i;
    }
    sort(k.begin(), k.end(), [&](int i, int j){return d[i] > d[j];});

    // for (auto i : k){
    //     cout << i << " ";
    // }

    ll res = 0;
    for (auto i : k){
        auto it = lower_bound(c.begin(), c.end(), l[i]);
        if (it == c.end()){
            continue;
        }

        res += *it - d[i];
        c.erase(it);
        if (c.size() == 0){
            break;
        }
    }

    for (int i = 0; i < c.size(); i++){
        res += c[i];
    }

    cout << res << endl;



    return 0;
}