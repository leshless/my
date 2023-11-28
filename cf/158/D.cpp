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
    int n;
    cin >> n;


    map <int, ll> freq;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (freq.count(x) == 0){
            freq[x] = 1;
        }else{
            freq[x] = freq[x] + 1;
        }
    }

    ll c = 0;
    for (auto [x, n] : freq){
        // cout << x << " " << n << endl;
        c += n * (n - 1) / 2;
    }
    c += freq[1] * freq[2];

    cout << c << endl;




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