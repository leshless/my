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

void solve(){
    int n, m;
    string s;
    cin >> n >> m >> s;

    ll res = 1;
    res *= (s[0] != '?');
    for (int i = 1; i < n-1; i++){
        res *= (s[i] == '?') * i;
        res %= mod;
    }
    cout << res << endl;

    while (m--){

    }


    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    solve();

    return 0;
}