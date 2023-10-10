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
    
    if (n <= 6){
        cout << "NO" << endl;
        return;
    }

    for (int a = 1; a <= 2; a++){
        for (int b = 1; b <= n-a; b++){
            int c = n-a-b;
            if ((a != b) && (b != c) && (c != a) && (b % 3 != 0) && (c % 3 != 0)){
                cout << "YES" << endl;
                cout << a << " " << b << " " << c << endl;
                return;
            }
        } 
    }


    cout << "NO" << endl;


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