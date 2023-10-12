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
    int n, p;
    cin >> n >> p;  

    vector <pair<ll, ll>> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i].first;
    }

    for (int i = 0; i < n; i++){
        cin >> a[i].second;
    }

    sort(a.begin(), a.end(), [](pair<ll, ll> p1, pair<ll, ll> p2){return p1.second < p2.second;});

    ll res = 0;
    ll more = 0;

    for (int i = 0; i < n; i++){
        if (more == 0){
            res += p;
        }else{
            more--;
        }

        if (a[i].second < p){
            res += min(a[i].first, (n - i - 1) - more) * a[i].second;
            more += min(a[i].first, (n - i - 1) - more);
        }
    }

    cout << res << endl;
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