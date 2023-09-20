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

void solve(){
    int n, m;
    cin >> n >> m;

    vector <uint> a(n);
    vector <uint> b(m);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    
    uint min = 0;
    uint max = 0;
    for (int i = 0; i < n; i++){
        min ^= a[i];
        max ^= a[i];
    }

    if (n & 1){
        for (int i = 0; i < m; i++){
            max |= b[i];
        }
    }else{
        min = ~min;
        for (int i = 0; i < m; i++){
            min |= b[i];
        }
        min = ~min;
    }

    cout << min << " " << max << endl;
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