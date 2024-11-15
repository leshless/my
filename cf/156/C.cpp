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
    int n;
    cin >> n;

    vector <string> mat(n);
    for (int i = 0; i < n; i++){
        cin >> mat[i];
    }

    ll res = 0;
    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            char m = max({mat[i][j], mat[j][n-i-1], mat[n-i-1][n-j-1], mat[n-j-1][i]});
            res += (m - mat[i][j]) +  (m - mat[j][n-i-1]) + (m - mat[n-i-1][n-j-1]) + (m - mat[n-j-1][i]);
        }
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