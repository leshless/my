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

    vector <set <int>> b(n);
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;

        for (int j = 0; j < m; j++){
            int x;
            cin >> x;
            b[i].insert(x);
        }
    }

    set <int> u;
    for (auto s : b){
        for (int x : s){
            u.insert(x);
        }
    }
    int t = u.size();

    sort(b.begin(), b.end(), [](set <int> s1, set <int> s2){return s1.size() > s2.size();});

    int res = 0;
    set <int> cur;
    for (auto s : b){
        int d = 0;
        for (auto x : s){
            if (cur.count(x) == 0){
                d++;
            }
        }
        if (res + d < t){
            res += d;
            vector <int> ncur;
            set_union(cur.begin(), cur.end(), s.begin(), s.end(), back_inserter(ncur));
            cur.insert(ncur.begin(), ncur.end());
        }
    }

    cout << endl;
    for (auto x : cur){
        cout << x << " ";
    }
    cout << endl << res << endl << endl;

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