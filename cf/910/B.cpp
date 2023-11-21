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

    vector <ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }


    ll res = 0;
    ll mn = nums[n-1];
    for (int i = n-2; i >= 0; i--){
        if (nums[i] > mn){
            if (nums[i] % mn == 0){
                res += nums[i] / mn - 1;
            }else{
                res += nums[i] / mn;
                mn = min(mn, max((nums[i] % mn) / 2, (nums[i] % (2*mn)) / 2));
            }
        }else{
            mn = min(mn, nums[i]);
        }
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