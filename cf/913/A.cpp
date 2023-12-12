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
    string p;
    cin >> p;

    char px = p[0];
    char py = p[1];

    for (int i = 0; i < 8; i++){
        if (i != px - 'a'){
            cout << char(i + 'a') << py << endl;; 
        }
    }
    for (int i = 0; i < 8; i++){
        if (i != py - '1'){
            cout << px << char(i + '1') << endl;
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