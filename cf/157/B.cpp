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

    vector <int> nums(2*n);
    for (int i = 0; i < 2*n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int s = 0;
    for (int i = 0; i < n-1; i++){
        s += abs(nums[i] - nums[i+1]) + abs(nums[i+n] - nums[i+1+n]);
    }
    cout << s << endl;

    for (int i = 0; i < n; i++){
        cout << nums[i] << " " << nums[i+n] << endl;
    }

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