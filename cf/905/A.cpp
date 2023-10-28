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
    string s;
    cin >> s;

    int res = s.size();
    
    for (char &a : s){
        a = (a == '0' ? '9' : a - 1);
    } 
    s = '0' + s;

    for (int i = 0; i < s.size()-1; i++){
        res += abs(s[i] - s[i+1]);
    }

    cout << res << endl;

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