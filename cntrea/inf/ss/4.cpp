#pragma GCC optimize("O3")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string alph = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map <char, int> val;
    for (int i = 0; i < 36; i++){
        val[alph[i]] = i;
    }

    string s;
    int d;
    cin >> s >> d;

    reverse(s.begin(), s.end());
    int n = s.size();
    ll rad = 1;

    ll res = 0;
    for (int i = 0; i < n; i++){
        res += rad *  val[s[i]];
        rad *= d;
    }

    ll l = 0;
    ll r = 1ll << 32;

    while (l < r){
        ll m = (l >> 1) + (r >> 1);

        if (m*m > res){
            r = m;
        }else if (m*m < res){
            l = m + 1;
        }else{
            l = m;
            break;
        }
    }

    cout << (l*l == res ? "YES" : "NO") << endl;

    return 0;
}