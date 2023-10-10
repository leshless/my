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

    if (k > 3){
        cout << 0 << endl;
    }else if (k == 1){
        cout << 1 << endl;
    }else if (k == 2){
        int res = (m > n ? n - 1 + (m / n) : m);
        cout << res << endl;
    }else{
        int res = (m > n ? m - n - (m / n) + 1: 0);
        cout << res << endl;
    }

    return;
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