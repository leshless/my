#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector <ll> nums;
    ll x;
    while (cin >> x){
        nums.push_back(x);
    }
    int n = nums.size();

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    ll r1 = 0;
    for (int i = (n / 3); i < n; i++){
        r1 += nums[i];
    }
    
    ll r2 = 0;
    for (int i = 0; i < n; i++){
        if (i % 3 != 2){
            r2 += nums[i];
        }
    }

    cout << r1 << " " << r2 << endl;

    return 0;
}