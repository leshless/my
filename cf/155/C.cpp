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

ll fact(ll n){

    ll res = 1;
    for (ll i = 2; i <= n; i++){
        res *= i;
        res %= 998244353;
    }

    return res;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    ll c = 0;
    ll r = 1;

    int d = 0;
    bool p = (s[0] == '1');
    for (int i = 1; i < n; i++){
        if ((s[i] == '1') == !p){
            p = !p;
            r *= (d + 1);
            r %= 998244353;
            d = 0;
        }else{
            c++;
            d++;
        }
    }
    r *= (d + 1);
    r %= 998244353;
    r = r * fact(c);
    r %= 998244353;


    cout << c << " " << r << endl;
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