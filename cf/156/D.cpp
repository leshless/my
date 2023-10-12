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

const ll mod = 998244353;

ll mdiv(ll a, ll b){
    ll x1 = mod;
    ll x2 = b;
    ll y1 = 0;
    ll y2 = a;

    while(x2 != 1){
        a = x1 / x2;

        ll tmpx = x1 - a * x2;
        ll tmpy = y1 - a * y2;

        x1 = x2;
        y1 = y2;
        x2 = tmpx;
        y2 = tmpy;
    }

    return ((y2 % mod) + mod) % mod;
}

void solve(){
    ll n, m;
    string s;
    cin >> n >> m >> s;

    ll res = 1;
    for (int i = 1; i < n-1; i++){
        if (s[i] == '?'){
            res *= i;
            res %= mod;
        }

    }
    cout << (s[0] == '?' ? 0 : res) << endl;

    while (m--){
        int i;
        char t;
        cin >> i >> t;
        i--;

        if (!i){
            s[i] = t;
            cout << (s[0] == '?' ? 0 : res) << endl;
            continue;
        }

        if (!(((s[i] == '<' || s[i] == '>') && (t == '<' || t == '>')) || (s[i] == '?' && t == '?'))){
            if (t == '?'){
                res *= i;
                res %= mod;
            }else{
                res = mdiv(res, i);
            }
        }

        cout << (s[0] == '?' ? 0 : res) << endl;
        s[i] = t;
    }


    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}