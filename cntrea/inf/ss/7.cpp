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

    string alph, w;
    cin >> alph >> w;

    ll d = alph.size();
    ll n = w.size();

    map <char, ll> val;
    for (int i = 0; i < d; i++){
        val[alph[i]] = i;
    }

    ll res = 0;
    ll c = 0;
    for (int i = n-1; i >= 0; i--){
        res += val[w[i]] * pow(d, c);
        c++;
    }

    cout << res + 1 << endl;


    return 0;
}