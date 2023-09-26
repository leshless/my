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

struct SegTree{
    vector <int> t;

    void build(int v, int l, int r, vector <int> &a){
        if(r - l == 1){
            t[v] = a[l];
            return;
        }

        int m = (l + r) / 2;
        build(v*2, l, m, a);
        build(v*2+1, m, r, a);

        t[v] = t[v*2] & t[v*2+1];
    }
    
    int get(int v, int l, int r, int L, int R){
        if (l >= R || L >= r){
            return 0xffffffff;
        }

        if (L <= l && r <= R){
            return t[v];
        }

        int m = (l + r) / 2;
        return get(v*2, l, m, L, R) & get(v*2+1, m, r, L, R);
    }


    SegTree(vector <int> &a){
        t.resize(4 * a.size());
        build(1, 0, a.size(), a);
    }
};

void solve(){
    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    auto t = SegTree(a);

    int q;
    cin >> q;
    while (q--){
        int l0, k;
        cin >> l0 >> k;
        l0--;

        if (a[l0] < k){
            cout << -1 << endl;
            continue;
        }

        int l = l0;
        int r = n;

        while (r - l != 1){
            int m = (l + r) / 2;

            if (t.get(1, 0, n, l0, m+1) >= k){
                l = m;
            }else{
                r = m;
            }
        }

        cout << l+1 << endl;
    }
    
    // while (q--){
    //     int l, r;
    //     cin >> l >> r;

    //     cout << t.get(1, 0, n, l, r) << endl;
    // }


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