#pragma GCC optimize("O3,unroll-loops")

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

    vector <int> a(n);
    map <int, bool> e;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        e[a[i]] = 1;
    }

    vector <int> first(k);
    int j = 0;
    for (int i = 0; i < n; i++){
        while (j+1 <= a[i]){
            first[j] = i;
            j++;
        }
    }

    vector <int> last(k);
    j = 0;
    for (int i = n-1; i >= 0; i--){
        while (j+1 <= a[i]){
            last[j] = i;
            j++;
        }
    }

    for (int i = 0; i < k; i++){
        cout << (last[i] - first[i] + 1) * 2 * e.count(i+1) << " ";
        // cout << last[i] << " ";
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