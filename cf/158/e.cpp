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
    int mn = INT_MAX;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        mn = min(mn, nums[i]);
    }

    int res;
    int i = 0;
    for (; i < n; i++){
        if (nums[i] == mn){
            res = i;
            break;
        }
    }

    for (; i < n-1; i++){
        if (nums[i] > nums[i+1]){
            cout << -1 << endl;
            return;
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