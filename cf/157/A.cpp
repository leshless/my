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
    int x, y, k;
    cin >> x >> y >> k;

    if ((x < y)){
        if (y - x > k){
            cout << x + k + 2 * (y - x - k) << endl;
        }else{
            cout << y << endl;
        }
    }else{
        cout << x << endl;
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