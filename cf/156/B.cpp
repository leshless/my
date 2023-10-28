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
    ll a, b, c;
    cin >> a >> b >> c;

    ll s = gcd(a, gcd(b, c));
    ll res = a / s + b / s + c / s - 3;

    cout << (res <= 3 ? "YES" : "NO") << endl;
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