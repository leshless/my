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
    int n, m;
    string x, s;
    cin >> n >> m >> x >> s;

    for (int k = 0; k < 1000; k++){
        int i = 0; 
        int j = 0;
        while (i != n && j != m){
            if (x[i] == s[j]){
                j++;
            }else{
                j = 0;
            }
            i++;
        }
        if (j == m){
            cout << k << endl;
            break;
        }
        if (n > m*2){
            cout << -1 << endl;
            break;
        }
        x += x;
        n += n;
    }


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