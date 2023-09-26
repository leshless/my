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

    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int c = 0;
    for (int i = 0; i < n; i++){
        c = (c + 1 != a[i] ? c + 1 : a[i] + 1);
    }

    cout << c << endl;
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