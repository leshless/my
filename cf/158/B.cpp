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

    vector <int> nums;
    nums.push_back(0);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (!i || x != nums[nums.size() - 1]){
            nums.push_back(x);
        }
    }
    n = nums.size();

    vector <int> extr;
    for (int i = 0; i < n; i++){
        if (i == 0 || i == n-1){
            extr.push_back(nums[i]);
        }else{
            if ((nums[i] > nums[i-1]) == (nums[i] > nums[i+1])){
                extr.push_back(nums[i]);
            }
        }
    }

    // for (auto x : extr){
    //     cout << x << " ";
    // }
    // cout << endl;

    ll res = -1;
    n = extr.size();
    bool f = 0;

    for (int i = 0; i < n; i++){
        if (f){
            res += extr[i] - extr[i-1];
        }
        f = !f;
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