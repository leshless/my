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

    int n;
    cin >> n;

    vector <ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    ll m = 0;
    for (auto x : nums){
        m = max(m, x);
    }

    int mp = 0;
    ll x = m;
    while (x <= 1e5){
        mp++;
        x *= m;
    }

    vector <ll> pows[mp+1];
    for (auto x : nums){
        ll q = x;
        for (int p = 1; p <= mp; p++){
            pows[p].push_back(q);
            q *= x;
        }
    }

    vector <ll> prefs[mp+1];
    for (int p = 1; p <= mp; p++){
        prefs[p].push_back(pows[p][0]);

        for (int i = 1; i < n; i++){
            prefs[p].push_back(prefs[p][i-1] + pows[p][i]);
        }
    }

    int cp = 1;

    int q;
    cin >> q; 

    while (q--){
        int t;
        cin >> t;
        
        if (t == 1){
            int p;
            cin >> p;

            if (cp*p <= mp){
                cp *= p;
            }
        }else if(t == 2){
            int p;
            cin >> p;

            if (cp % p == 0){
                cp /= p;
            }

        }else{
            int l, r;
            cin >> l >> r;
            l--; r--;

            ll res;
            if (l != 0){
                res = prefs[cp][r] - prefs[cp][l-1];
            }else{
                res = prefs[cp][r];
            }

            cout << res << endl;

        }
    }




    return 0;
}
    