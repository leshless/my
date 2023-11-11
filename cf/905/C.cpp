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
    int n, k;
    cin >> n >> k;

    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int res = 10;
    for (int a : nums){
        for (int b = a; b < a+5; b++){
            if (b % k == 0){
                res = min(res, b-a);
            }
        }
    }

    if (k == 4){
        int even = 0;
        for (int a : nums){
            if (!(a & 1)){
                even++;
            }
        }
        if (even >= 2){
            res = 0;
        }else{
            res = min(res, 2 - even);
        }
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