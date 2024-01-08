#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
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

    vector <ll> nums(n);
    map <ll, int> pres;
    for (int i =0 ; i < n; i++){
        ll x;
        cin >> x;

        nums[i] = x;
        pres[x] = i+1;
    }

    ll res = 0;
    int p1 = 1;
    int p2 = 1;

    for (int i = 0; i < n; i++){
        ll x = nums[i];
        for (ll y = 1; (y*y <= x) && (x - y > res); y++){
            if (x % y){
                continue;
            }
            if (pres[y] && (x - y > res)){
                res = x - y;
                p1 = pres[y];
                p2 = i + 1;
            }
            if (pres[x / y] && (x - (x / y) > res)){
                res = x - (x / y);
                p1 = pres[x / y];
                p2 = i + 1;
            }
        }
    }

    cout << p1 << " " << p2 << endl;

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
    