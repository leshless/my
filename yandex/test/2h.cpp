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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, v, p;
    ll m;
    cin >> n >> m >> v >> p;
    p--;

    vector <ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());


    vector <ll> suf(n, 0);
    for (int i = 0; i < n; i++){
        if (i > p){
            if (i == p+1){
                suf[i] = a[i] + m - a[p];
            }else{
                suf[i] = suf[i-1] - (i - p - 1) * (a[i-1] - a[i]) + (a[i] + m - a[i-1]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++){
        if (a[i] + m < a[p]){
            break;
        }
        if (i <= p){
            res++;
            continue;
        }
        if (n - i + p >= v){
            res++;
            continue;
        }
        if (m * (v - (n - i + p)) <= suf[i]){
            res++;
            continue;
        }
    }

    cout << res << endl;


    return 0;
}   