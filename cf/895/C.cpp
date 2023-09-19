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
    int l, r;
    cin >> l >> r;

    if (r < 4){
        cout << -1 << endl;
        return;
    }

    if (l != r){
        cout << r / 2 << " " << r / 2 << endl;
    }else{
        for (int i = 2; i <= sqrt(l); i++){
            if (gcd(i, l-i) != 1){
                cout << i << " " << l-i << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
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