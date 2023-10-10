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
    int n, m;
    cin >> n >> m;

    ll res = 0;
    


    while (n % m != 0){
        ban[n] = 1;
        while (n < m){
            res += n;
            n *= 2;
        }
        n -= m * (n / m);
        if (ban.count(n) != 0){
            res = -1;
            break;
        }
    }

    cout << res << endl;

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