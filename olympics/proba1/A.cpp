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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    ll res = 0;
    if (k != 1){
        res += n * (m - 1);
    }
    if (m < k){
        res += m * (n - 1);
    }

    cout << res << endl;
    

    return 0;
}