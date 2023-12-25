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
    int a, b, c;
    cin >> a >> b >> c;

    bool r1 = ((b & 1) == (c & 1));
    bool r2 = ((a & 1) == (c & 1));
    bool r3 = ((b & 1) == (a & 1));

    cout << r1 << " " << r2 << " " << r3 << endl;
    

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