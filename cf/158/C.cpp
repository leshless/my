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

    int res = nums[0];
    int cur = nums[0];
    for (int i = 1; i < n; i++){
        if ((nums[i] & 1) != (nums[i-1] & 1)){
            if (cur < 0){
                cur = nums[i];
            }else{
                cur += nums[i];
            }
        }else{
            cur = nums[i];
        }
        res = max(res, cur);
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