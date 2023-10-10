#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define peque priority_queue
#define map unordered_map

struct entry{
    ll p;
    int i;
    entry *l;
    entry *r;

    entry(ll pn, int in, entry *ln, entry *rn){
        p = pn;
        i = in;
        l = ln;
        r = rn;
    }
};

map <int, string> paths;

void restore(entry a, string path){
    if (a.l != nullptr && a.r != nullptr){
        restore(*(a.l), path + "0");
        restore(*(a.r), path + "1");
    }else{
        paths[a.i] = path;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    auto cmp = [](entry a, entry b){return a.p > b.p;};
    peque <entry, vector <entry>, decltype(cmp)> pq(cmp);
    vector <ll> ps;

    ll p;
    int i = 0;
    while (cin >> p){
        ps.push_back(p);
        pq.push({p, i++, nullptr, nullptr});
    }

    while (pq.size() > 2){
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();
        pq.push({a.p + b.p, -1, new entry(a.p, a.i, a.l, a.r), new entry(b.p, b.i, b.l, b.r)});
    }

    auto e = pq.top();
    pq.pop();
    restore(e, "0");
    
    e = pq.top();
    pq.pop();
    restore(e, "1");

    for (int j = 0; j <= i; j++){
        cout << paths[j] << " ";
    }


    return 0;
} 