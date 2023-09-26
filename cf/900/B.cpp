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
    a[0] = 2;
    a[1] = 3;

    for (int i = 2; i < n; i++){
        a[i] = ((a[i-1]*2+1) % 3 == 0 ? a[i-1]+2 : a[i-1]+1);
    }

    for (int x : a){
        cout << x << " ";
    }
    cout << endl;

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