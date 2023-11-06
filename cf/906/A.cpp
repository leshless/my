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

    map <int, int> freq;
    for (int x : nums){
        if (freq.count(x) != 0){
            freq[x]++;
        }else{
            freq[x] = 1;
        }
    }

    if (freq.size() > 2){
        cout << "NO" << endl;
    }else if (freq.size() == 2){
        for (auto [x, a] : freq){
            if (a == n/2){
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
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