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
    int n, k, x;
    cin >> n >> k >> x;

    int res;

    if (min(n, x + 1) < k){
        res = -1;
    }else if (k == x){
        res = (k - 1) * k / 2 + (k - 1) * (n - k);
    }else{
        res = (k - 1) * k / 2 + x * (n - k);
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