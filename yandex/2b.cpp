#pragma GCC optimize("O3,unroll-loops")

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

int main(){
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    vector <ull> nums;

    for (int i = 0; i < 62; i++){
        for (int j = i+1; j < 63; j++){
            for (int k = j+1; k < 64; k++){
                nums.push_back((1ull << i) + (1ull << j) + (1ull << k));
            }
        }
    }
    sort(nums.begin(), nums.end());

    int t;
    cin >> t;

    while (t--){
        ull x;
        cin >> x;

        if (x < 7){
            cout << -1 << endl;
        }else{
            cout << *(upper_bound(nums.begin(), nums.end(), x) - 1) << endl;
        }
    }   

    return 0;
}