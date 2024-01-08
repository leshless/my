#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

void solve(){
    ll n;
    cin >> n;

    ll s = sqrtl(n);
    ll res = (s*s == n) && !(s & n);
    
    int mp = 1;
    ll c = s;
    while(c > 0){
        c /= 2;
        mp++;
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
    