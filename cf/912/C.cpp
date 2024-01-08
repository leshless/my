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

    vector <ll> suf(n);
    suf[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; i--){
        suf[i] = nums[i] + suf[i+1];
    }

    ll res = nums[n-1];
    for (int i = n-2; i >= 0; i--){
        if (suf[i+1] > 0){
            res += suf[i+1];
        }
        res += nums[i];
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