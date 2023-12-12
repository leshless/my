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
    ll n, p, l, t;
    cin >> n >> p >> l >> t;

    ll z = n / 7 + (n % 7 != 0);
    ll d1 = (l + 2 * t);
    ll d2 = (l + t);
    ll d3 = l;

    ll res = 0;

    ll x = min(p / d1 + (p % d1 != 0), z / 2);
    p -= d1 * x;
    res += x;

    if ((p > 0) && (z % 2)){
        p -= d2;
        res += 1;
    }

    if (p > 0){
        res += p / d3 + (p % d3 != 0);
    }

    cout << n - res << endl;


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