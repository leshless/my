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

const ll m = 998244353;
ll dp[100001];


void solve(){
    dp[0] = 1;
    for (int i = 1; i <= 100000; i++){
        dp[i] = (dp[i-1] * 2) % m;
    }



    int n;
    cin >> n;

    vector <ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j+=(i + 1)){
            a[i] = max(a[i], a[j]);
        }
    }

    vector <int> ord;
    for (int i = 0; i < n; i++){
        ord.push_back(i);
    }
    sort(ord.begin(), ord.end(), [&](int i, int j){return a[i] > a[j];});

    int pow = n - 1;
    ll res = 0;
    for (auto i : ord){
        ll s = a[i];
        res += (s * dp[pow]) % m;
        res %= m;
        pow--;
    }

    cout << res << endl;


    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    solve();

    return 0;
}