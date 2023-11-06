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
    string s, t;
    cin >> n >> m >> s >> t;

    bool f = 1;
    for (int i = 0; i < n-1; i++){
        if (s[i] == s[i+1]){
            f = 0;
        }
    }

    if (f){
        cout << "YES" << endl;
    }else{
        f = 1;
        for (int i = 0; i < m-1; i++){
            if (t[i] == t[i+1]){
                f = 0;
            }
        }

        if (f){
            if (t[0] == t[m-1]){
                f = 1;
                for (int i = 0; i < n-1; i++){
                    if (s[i] == s[i+1] && s[i] == t[0]){
                        f = 0;
                    }
                }

                if (f){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }

            }else{
                cout << "NO" << endl;
            }

        }else{
            cout << "NO" << endl;
        }
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