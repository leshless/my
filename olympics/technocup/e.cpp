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

    int n, k;
    cin >> n >> k;

    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector <vector <int>> pos(n);
    int cur = -1;
    ll res = 0;
    for (int i = 0; i < n; i++){
        int x = nums[i] - 1;

        pos[x].push_back(i);
        int m = pos[x].size();
        if (m >= k){
            if (m - k == 0){
                cur = max(cur, pos[x][m-k]);
            }else{
                cur = max(cur, pos[x][m-k] - pos[x][m-k-1] - 1);
            }
        }
        cout << cur << " ";

        res += cur + 1;
    }
    cout << endl;

    cout << res << endl;

    return 0;
}
    