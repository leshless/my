#include <bits/stdc++.h>

using namespace std;

#define ll long long


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

        t[v] = t[v*2] + t[v*2+1];
    }
    
    int get(int v, int l, int r, int L, int R){
        if (l >= R || L >= r){
            return 0;
        }

        if (l <= L && R <= r){
            return t[v];
        }

        return get(v*2, l, r, L, R) + get(v*2+1, l, r, L, R);
    }

    void upd(int v, int l, int r, int i, int val){
        if (i >= r || i < l){
            return;
        }

        if(l - r == 1){
            t[v] = val;
        }

        int m = (l + r) / 2;
        upd(v, l, m, i, val);
        upd(v, m, r, i, val);

        t[v] = t[v*2] + t[v*2+1];
    }


    SegTree(vector <int> &a){
        t.resize(4 * a.size());
        build(1, 0, a.size(), a);
    }
};


int main(){
    vector <int> a;
    auto t = SegTree(a);

    
    return 0;
}