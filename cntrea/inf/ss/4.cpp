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

    string a = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map <char, int> val;
    for (int i = 0; i < 36; i++){
        val[a[i]] = i;
    }

    string s;
    ll d;
    cin >> s >> d;

    ll n = s.size();
    ll c = 0;

    ll res = 0;
    for (int i = n-1; i >= 0; i--){
        res += val[s[i]] * pow(d, c);
        c++;
    }

    ll sres = sqrt(res);
    cout << (sres * sres == res ? "YES" : "NO") << endl;


    return 0;
}