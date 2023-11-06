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

    sort(nums.begin(), nums.end());

    ll res = 0;
    ll x = 0;
    int i = 0;
    int j = n-1;

    while (i < j){
        if (nums[i] + x > nums[j]){
            res += nums[j] - x + 1;
            nums[i] -= nums[j] - x;
            x = 0;
            j--;
        }else if(nums[i] + x < nums[j]){
            x += nums[i];
            res += nums[i];
            i++;
        }else{
            x = 0;
            res += nums[i] + 1;
            i++;
            j--;
        }
    }

    if (i == j){
        if (nums[i]){
            if (nums[i] == 1){
                res++;
            }else{
                res += (nums[i] + x) / 2 - x + 1 + (nums[i] + x) % 2;
            }
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