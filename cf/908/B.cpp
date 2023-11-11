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

    for (int a : nums){
        if (freq.count(a) == 0){
            freq[a] = 1;
        }else{
            freq[a]++;
        }
    }

    map <int, bool> num;
    map <int, bool> once;

    bool s = 0;    
    for (int a : nums){
        if (freq[a] > 1){
            if (num.count(a) == 0){
                num[a] = s;
                once[a] = 0;
                s = !s;
            }
        }
    }

    if (num.size() < 2){
        cout << -1 << endl;
        return;
    }

    for (int a : nums){
        int b;
        if (num.count(a) == 0){
            b = 3;
        }else{
            b = 1 + num[a] + once[a];
            once[a] |= 1; 
        }
        cout << b << " ";
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