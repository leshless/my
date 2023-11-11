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
    int n, q;
    cin >> n >> q;

    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector <int> queires;
    for (int i = 0; i < q; i++){
        int x;
        cin >> x;

        if (queires.size() == 0 || x < queires[queires.size()-1]){
            queires.push_back(x);
        }
    }

    for (int &x : nums){
        for (int a : queires){
            if (!(x & ((1 << a) - 1))){
                x += 1 << (a - 1);
            }
        }
    }

    for (int x : nums){
        cout << x << " ";
    }
    cout << endl;

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