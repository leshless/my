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
    string s;
    cin >> n >> s;

    for (int i = 0; i < n-2; i++){
        if ((s[i] == '.') && (s[i+1] == '.') && (s[i+2] == '.')){
            cout << 2 << endl;
            return;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++){
        if ((s[i] == '.')){
            res++;
        }
    }

    cout << res << endl;



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