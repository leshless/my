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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int bc = 0;
    for (auto x : s){
        bc += x == 'B';
    }

    if (bc == k){
        cout << 0 << endl;
    }else if (bc < k){
        cout << 1 << endl;
        int c = 0;
        for (int i = 0; i < n; i++){
            c += s[i] == 'A';
            if (c == k - bc){
                cout << i+1 << " " << "B" << endl;
                break;
            }
        }
    }else{
        cout << 1 << endl;
        int c = 0;
        for (int i = 0; i < n; i++){
            c += s[i] == 'B';
            if (c == bc - k){
                cout << i+1 << " " << "A" << endl;
                break;
            }
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