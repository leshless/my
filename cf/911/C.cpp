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

const int N = 3 * 1e5 + 228;
pair<int, int> g[N];
string s;

int dfs(int u){
    int l = g[u].first;
    int r = g[u].second;
    if ((!l) && (!r)){
        return 0;
    }

    int res = INT_MAX;
    if (l){
        res = min(res, dfs(l) + (s[u-1] != 'L'));
    }
    if (r){
        res = min(res, dfs(r) + (s[u-1] != 'R'));
    }

    return res;
}

void solve(){
    int n;
    cin >> n >> s;

    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        g[i+1] = {l, r};
    }

    cout << dfs(1) << endl;


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