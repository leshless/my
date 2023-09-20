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
#define peque priority_queue
#define map unordered_map

vector <int> dp[51][51];

void fill(){
    for (int i = 0; i < 51; i++){
        for (int j = 0; j < 51; j++){
            for (int k = 1; k < 51; k++){
                if ((i % k != i) && ((i % k == j) || (dp[i % k][j].size() != 0))){
                    dp[i][j].push_back(k);
                }
            }
        }
    }

    for (int i = 0; i < 51; i++){
        for (int j = 0; j < 51; j++){
            sort(dp[i][j].begin(), dp[i][j].end());
        }
    }
}

bool found(vector <int> &nums, int a){
    for (auto el : nums){
        if (el == a){
            return 1;
        }
    }
    return 0;
}

void custom_timeout(int dur) {
    auto st = high_resolution_clock::now();
    while (true) {
        auto nt = high_resolution_clock::now();
        auto dt = duration_cast<milliseconds>(nt - st).count();
        if (dt >= dur) {
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill();
    // for (int i = 0; i < 51; i++){
    //     for (int j = 0; j < 51; j++){
    //         cout << i << "->" << j << endl;
    //         for (auto el : dp[i][j]){
    //             cout << el << " ";
    //         }
    //         cout << endl << endl;
    //     }
    // }

    int n;
    cin >> n;

    custom_timeout(10 * n);

    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    ll res = 0;
    for (int k = 50; k >= 1; k--){
        for (int i = 0; i < n; i++){
            if (a[i] == b[i]){
                continue;
            }
            if (dp[a[i]][b[i]].size() == 0){
                goto bad;
            }else{
                if (dp[a[i]][b[i]][0] == k){
                    for (int j = 0; j < n; j++){
                        if (found(dp[a[j]][b[j]], k)){
                            a[j] %= k;
                        }
                    }
                    res += pow(2ll, k);
                    break;
                }
            }
        }
    }

    cout << res << endl;
    return 0;

    bad:
        cout << -1 << endl;
        return 0;
}