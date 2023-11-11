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

    vector <string> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector <int> row(50, 0);
    vector <vector<int>> dp(10, row);

    for (string s : nums){
        int sum = 0;
        for (char c : s){
            sum += c - '0';
        }

        dp[s.size()][sum] += 1;
    }

    ll res = 0;
    for (string s : nums){
        int sum = 0;
        int l = s.size();
        for (char c : s){
            sum += c - '0'; 
        }

        int pref = 0;
        for (int i = 0; i < l; i++){
            pref += s[i] - '0';
            if (i >= l / 2){
                res += dp[(i + 1) - (l - (i + 1))][pref - (sum - pref)];
            }
        }

        int suf = 0;
        for (int i = l-1; i >= 0; i--){
            suf += s[i] - '0';
            if (i <= l / 2){
                res += dp[(l - i) - (l - (l - i))][suf - (sum - suf)];
            }
        }
    }


    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 50; j++){ 
            res -= dp[i][j] * (dp[i][j] - 1);
        }
    }

    cout << res - n << endl;

    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}