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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    ll res = 0;
    ll cur = 0;
    for (int i = 0; i < n; i++){
        if (cur <= 0){
            cur = nums[i];
        }else{
            cur += nums[i];
        }

        res = max(res, cur);
    }

    
    vector <ll> pref(n);
    pref[0] = nums[0];
    for (int i = 1; i < n; i++){
        pref[i] = pref[i-1] + nums[i];
    }
    for (int i = 1; i < n; i++){
        pref[i] = max(pref[i-1], pref[i]);
    }

    vector <ll> suf(n);
    suf[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; i--){
        suf[i] = suf[i+1] + nums[i];
    }
    for (int i = n-2; i >= 0; i--){
        suf[i] = max(suf[i+1], suf[i]);
    }

    for (int i = 1; i < n; i++){
        res = max(res, suf[i] + pref[i-1]);
    }

    cout << res << endl;

    

    return 0;
}