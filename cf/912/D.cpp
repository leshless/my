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
    int n, q;
    cin >> n >> q;

    vector <ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    while(q--){
        ll k;
        cin >> k;

        vector <ll> cp;
        copy(nums.begin(), nums.end(), back_inserter(cp));

        ll res = 0;

        for (ll i = 63; i >= 0; i--){
            ll sum = 0;
            for (ll x : cp){
                if (!((x >> i) & 1)){
                    sum += (1ll << i) - (x & ((1ll << i) - 1));
                    if (sum >= 1e18){
                        break;
                    }
                }
            }
            // cout << i << " " << sum << endl;
            if (sum <= k){
                k-=sum;
                res += (1ll << i);
                for (ll &x : cp){
                    if ((!((x >> i) & 1))){
                        x = 0;
                    }
                }
            }
        }

        cout << res << endl;

    }

    


    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    solve();

    return 0;
}