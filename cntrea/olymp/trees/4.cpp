#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct entry{
    ll oo;
    ll io;
    ll oi;
    ll ii;
};

struct SegTree{
    vector <entry> t;

    void build(int v, int l, int r, vector <ll>&a){
        if (r - l == 1){
            t[v] = {0, 0, 0, a[l]};
            return;
        }

        int m = (r + l) / 2;
        build(v*2, l, m, a);
        build(v*2+1, m, r, a);

        auto le = t[v*2];
        auto re = t[v*2+1];

        // ПИЗДЯТИНА
        t[v].oo = max({le.oi + re.oo, le.oo + re.io, le.oo + re.oo, le.oo, re.oo, le.oi, re.io, 0ll});
        t[v].io = max(max(le.ii, le.io), max({le.ii + re.oo, le.io + re.oo, le.io + re.io}));
        t[v].oi = max(max(re.ii, re.oi), max({le.oo + re.ii, le.oo + re.oi, le.oi + re.oi}));
        t[v].ii = max({le.io + re.oi, le.ii + re.oi, le.io + re.ii});
    }
    
    void upd(int v, int l, int r, int i, ll val){
        if (r - l == 1){
            t[v] = {0, 0, 0, val};
            return;
        }

        int m = (r + l) / 2;
        if (i < m){
            upd(v*2, l, m, i, val);
        }else{
            upd(v*2+1, m, r, i, val);   
        }

        auto le = t[v*2];
        auto re = t[v*2+1];

        // ПИЗДЯТИНА
        t[v].oo = max({le.oi + re.oo, le.oo + re.io, le.oo + re.oo, le.oo, re.oo, le.oi, re.io, 0ll});
        t[v].io = max(max(le.ii, le.io), max({le.ii + re.oo, le.io + re.oo, le.io + re.io}));
        t[v].oi = max(max(re.ii, re.oi), max({le.oo + re.ii, le.oo + re.oi, le.oi + re.oi}));
        t[v].ii = max({le.io + re.oi, le.ii + re.oi, le.io + re.ii});
    }

    ll getmax(){
        return max({t[1].oo, t[1].io, t[1].oi, t[1].ii});
    }

    SegTree(vector <ll> &a){
        t.resize(4 * a.size());
        build(1, 0, a.size(), a);
    }
};


int main(){
    string input;
    getline(cin, input);
    istringstream iss(input);

    vector <ll> a;
    ll x;
    while (iss >> x){
        a.push_back(x);
    }

    int n = a.size();
    auto tree = SegTree(a);
    cout << tree.getmax() << endl;

    // for (auto v : tree.t){
    //     printf("%lld, %lld, %lld, %lld\n", v.oo, v.oi, v.io, v.ii);
    // }

    int k;
    while (cin >> k >> x){
        tree.upd(1, 0, n, k, x);
        cout << tree.getmax() << endl;
    }

    
    return 0;
}