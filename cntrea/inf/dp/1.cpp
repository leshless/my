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

    int k;
    cin >> k;

    vector <int> nums;
    int x;
    while (cin >> x){
        nums.push_back(x);
    }
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int i = 0;
    while (k && i < n){
        if (k >= nums[i]){
            k -= nums[i];
            i++;
        }
    }

    return 0;
}