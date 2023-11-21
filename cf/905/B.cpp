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
    int n, k;
    string s;
    cin >> n >> k >> s;

    map <char, int> c;
    for (char x : s){
        if (c.count(x) == 0){
            c[x] = 1;
        }else{
            c[x]++;
        }
    }

    int odd = 0;
    for (auto [x, a] : c){
        odd += (a & 1);
    }

    cout << (odd - 1 > k ? "NO" : "YES") << endl;
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