#pragma GCC optimize("O3")

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
    int n, m, k;
    cin >> n >> m >> k;

    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector <int> b(m);
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    if (a[0] < b[m-1]){
        swap(a[0], b[m-1]);
    }

    if (!(k & 1)){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());


        if (b[0] < a[n-1]){
            swap(b[0], a[n-1]);
        }    
    }

    ll res = 0;
    for (int i = 0; i < n; i++){
        res += a[i];
    }

    cout << res << endl;
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