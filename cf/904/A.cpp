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


int sum (int x){
    int res = 0;
    while (x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve(){
    int x, k;
    cin >> x >> k;

    int res = 0;
    for (res = x; res <= x+100; res++){
        if (sum(res) % k == 0){
            break;
        }
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