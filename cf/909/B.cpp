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

    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector <ll> pref(n);
    pref[0] = nums[0];
    for (int i = 1; i < n; i++){
        pref[i] = pref[i-1] + nums[i];
    }


    ll res = 0;
    for (int k = 1; k <= n; k++){
        if (n % k){
            continue;
        }

        ll mn = LLONG_MAX;
        ll mx = 0;

        for (int i = 0; i < n; i+=k){
            ll sum = pref[i + k - 1];
            if (i != 0){
                sum -= pref[i-1];
            }
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        res = max(res, mx - mn);
    }


    cout << res << endl;
    

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