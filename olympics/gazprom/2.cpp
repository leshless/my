#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define map unordered_map

using namespace std;

template <typename T>
void Print(vector <T> &vec) {
    for (auto &x : vec){
        cout << x << " ";
    }
    cout << "\n";
}

map <int, bool> ban;
vector <int> g[310];

int solve(int u, int acc) {
    int res = -1;
    for (int v : g[u]) {
        if (!ban[v]) {
            ban[v] = 1;

            if (res == -1) {
                res = solve(v, acc);
            } else {
                res = min(res, solve(v, acc));
            }

            ban.erase(v);
        }
    }

    if (res == -1) {
        if (u == 0){
            return acc;
        }else{
            return solve(0, acc+1);
        }
    } else {
        return res;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<set<int>> sets;
    sets.push_back(set<int>());
    
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        
        set<int> u;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            u.insert(x);
        }
        
        for (int j = 0; j < sets.size(); j++) {
            set<int> v = sets[j];
            if (includes(v.begin(), v.end(), u.begin(), u.end())) {
                g[i].push_back(j);
            }
            if (includes(u.begin(), u.end(), v.begin(), v.end())) {
                g[j].push_back(i);
            }
        }
        
        sets.push_back(u);
    }

    // for (int i = 0; i <= n; i++){
    //     Print(g[i]);
    // }

    cout << solve(0, 0) << endl;

    return 0;
}