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

ll gcd(ll a, ll b){
        while (b != 0){
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}


void solve(){
    int n;
    cin >> n;


    vector <ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    ll mx = nums[0];
    ll g = 0;

    for (int i = 0; i < n; i++){
        g = gcd(mx - nums[i], g);
    }
    g = max(g, 1ll);

    // cout << g << endl;

    ll ins = mx - g;
    for (int i = 1; i < n; i++){
        if (nums[i] != ins){
            break;
        }else{
            ins -= g;
        }
    }

    // cout << ins << endl;

    ll res = (mx - ins) / g;
    for (auto x : nums){
        res += (mx - x) / g;
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