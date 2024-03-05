#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
#define For(i, l, r) for (int i=l; i<r; ++i)

const int N = (1 << 20);

struct Tree{
    vi nums;
    vll tval;
    vll tpush;

    void build(int v, int tl, int tr) {
        tpush[v] = -1;
        if (tl + 1 == tr){
            tval[v] = nums[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm, tr);

        tval[v] = tval[2*v] + tval[2*v+1];
    }

    void push(int v, int tl, int tr) {
        if (tpush[v] == -1) {
            return;
        }
        if (tl + 1 == tr) {
            tval[v] = tpush[v];
        }else{
            tval[v] = tpush[v] * (tr - tl);
            tpush[2*v] = tpush[v];
            tpush[2*v+1] = tpush[v];
        }
        tpush[v] = -1;
    }

    void upd(int v, int tl, int tr, int l, int r, int x, int k) {
        push(v, tl, tr);
        if (tl >= r || l >= tr) {
            return;
        }
        
        if (l <= tl && tr <= r) {
            tpush[v] = x;
            push(v, tl, tr);
            return;
        }

        int tm = (tl + tr) / 2;

        if (((tr - tl) >> 1) & k){
            upd(2*v+1, tl, tm, l, r, x, k);
            upd(2*v, tm, tr, l, r, x, k);
        }else{
            upd(2*v, tl, tm, l, r, x, k);
            upd(2*v+1, tm, tr, l, r, x, k);
        }

        tval[v] = tval[v*2] + tval[v*2+1];
    }

    ll get(int v, int tl, int tr, int l, int r, int k) {
	push(v, tl, tr);
	if (tl >= r || l >= tr) {
		return 0;
	}
	
    if (l <= tl && tr <= r) {
		return tval[v];
	}

	int tm = (tl + tr) / 2;

    if (((tr - tl) >> 1) & k){
        return get(2*v+1, tl, tm, l, r, k) + get(2*v, tm, tr, l, r, k);
    }
    return get(2*v, tl, tm, l, r, k) + get(2*v+1, tm, tr, l, r, k);
}

    Tree(vi &a){
        nums = a;
        int n = nums.size();
        tval.resize(2*n);
        tpush.resize(2*n);
        build(1, 0, n);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    n = (1 << n);

    vi nums(n);
    For(i, 0, n){
        cin >> nums[i];
    }
    auto tree = Tree(nums);

    int q;
    cin >> q;

    while (q--){
        int t, l, r, k, v;
        cin >> t;
        if (t == 1){
            cin >> l >> r >> k >> v;
            tree.upd(1, 0, n, l, r+1, v, k);
        }else{
            cin >> l >> r >> k;
            cout << tree.get(1, 0, n, l, r+1, k) << "\n";
        }
    }


    return 0;
}