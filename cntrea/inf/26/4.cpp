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
    reverse(nums.begin(), nums.end());

    int res = 1;
    int prev = nums[0];
    for (int i = 1; i < n; i++){
        if (nums[i] + k <= prev){
            prev = nums[i];
            res++;
        }
    }

    cout << res << " " << prev << endl;

    

    return 0;
}