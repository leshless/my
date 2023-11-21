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

ll sol(vector <int> nums){
    int n = nums.size() / 2;

    ll res = 0;
    ll cur = 0;
    int j = 0;
    for (int i = 0; i < 2*n; i++){
        if (i - n == j){
            cur -= nums[j];
            j++;
            while((nums[j] <= 0) && (j != i)){
                cur -= nums[j];
                j++;
            }
        }
        
        if (cur <= 0){
            cur = nums[i];
            j = i;
        }else{
            cur += nums[i];
        }

        res = max(res, cur);
    }

    return res;
}

ll lazy(vector <int> nums){
    int n = nums.size() / 2;
    
    vector <ll> pref(n*2);
    pref[0] = nums[0];
    for (int i = 1; i < n*2; i++){
        pref[i] = pref[i-1] + nums[i];
    }

    ll res = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < min(2*n, i+n); j++){
            ll sum = pref[j];
            if (i){
                sum -= pref[i-1];
            }

            res = max(res, sum);
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));

    int n = rand() % 100 + 1;

    vector <int> nums(2*n);
    for (int i = 0; i < n; i++){
        int x = rand() % 21 - 10; 
        nums[i] = x;
        nums[n + i] = x;
    }

    for (int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    for (auto x : nums){
        cout << x << " ";
    }
    cout << endl;

    cout << lazy(nums) << endl;
    cout << sol(nums) << endl;
    

    return 0;
}