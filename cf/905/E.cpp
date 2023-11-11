#pragma GCC optimize("O3")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

void solve(){
    int n;
    cin >> n;

    vector <ull> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }


    ll res = 0;
    for (int i = 1; i < n; i++){
        int l = 0;
        int r = 38;

        while (l < r){
            int m = (l >> 1) + (r >> 1);

            if (nums[i] << m < nums[i-1]){
                l = m+1;
            }else{
                r = m;
            }
        }

        nums[i] <<= l;
        res += l;
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