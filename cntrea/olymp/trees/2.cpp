#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double

struct Node{
    Node *l;
    Node *r;
    int ls;
    int rs;
    ll v;

    void add(ll val){
        if (val < v){
            ls++;
            if (l != NULL){
                l->add(val);
            }else{
                l = new Node(val);
            }
        }else{
            rs++;
            if (r != NULL){
                r->add(val);
            }else{
                r = new Node(val);
            }
        }
    }


    ll find(int k){
        if (rs == k-1){
            return v;
        }


        if (rs >= k){
            if (r == NULL){
                return LLONG_MIN;
            }
            return r->find(k);
        }else{
            if (l == NULL){
                return LLONG_MIN;
            }
            return l->find(k-rs-1);
        }
    }

    Node(ll val){
        l = NULL;
        r = NULL;
        ls = 0;
        rs = 0;
        v = val;
    }
};





int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    ll r;
    cin >> r;
    auto root = Node(r);
    if (k == 1){
        cout << r << " ";
    }else{
        cout << "NO ";
    }


    ll a;
    while (cin >> a){
        root.add(a);
        ll res = root.find(k);
        if (res != LLONG_MIN){
            cout << res << " ";
        }else{
            cout << "NO ";
        }
    }



    return 0;
}