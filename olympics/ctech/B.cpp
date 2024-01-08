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

void solve(){
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    map <char, bool> occ;

    for (char x : s){
        if (occ.count(x) == 0){
            occ[x] = 1;
        }else{
            occ.erase(x);
        }
    }

    if (occ.size() > m){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

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
    