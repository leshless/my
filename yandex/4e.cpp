#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define uint unsigned int

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k1;
    cin >> n >> k1;

    vector <int> a;

    for (int i = 0; i < n; i++){
        char t;
        cin >> t;
        switch (t){
        case 'M':
            a.push_back(0);
            break;
        case 'P':
            a.push_back(1);
            break;
        case 'G':
            a.push_back(2);
            break;
        }
    }

    vector <int> row(k1+1, 0x80000000);
    vector <vector <int>> layer(3, row);
    vector <vector <vector<int>>> dp(n, layer);

    dp[0][0][k1] = (a[0] == 0);
    dp[0][1][k1] = (a[0] == 1);
    dp[0][2][k1] = (a[0] == 2);
    
    if (k1 != 0){
        dp[0][0][k1-1] = !(a[0] == 0);
        dp[0][1][k1-1] = !(a[0] == 1);
        dp[0][2][k1-1] = !(a[0] == 2);
    }    

    for (int i = 1; i < n; i++){
        for (int t = 0; t <= 2; t++){
            for (int k = 0; k <= k1; k++){
                if (k == k1){
                    dp[i][t][k] = dp[i-1][t][k] + (a[i] == t);
                }else{
                    dp[i][t][k] = max({dp[i-1][0][k + !(t == 0)] + (a[i] == 0), dp[i-1][1][k + !(t == 1)] + (a[i] == 1), dp[i-1][2][k + !(t == 2)] + (a[i] == 2)});
                }
            }
        }
    }

    int res = 0;
    for (auto row : dp[n-1]){
        for (auto el : row){
            res = max(res, el);
        }
    }

    cout << res << endl;

    return 0;
}