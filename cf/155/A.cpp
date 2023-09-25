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

    vector <int> s(n);
    vector <int> e(n);

    for (int i = 0; i < n; i++){
        cin >> s[i] >> e[i];
    }

    int res = 1;

    for (int i = 1; i < n; i++){
        if (e[i] >= e[0]){
            res = max(res, s[i] + 1);
        }
    }

    cout << (res > s[0] ? -1 : res) << endl;
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