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

struct entry{
    ll n;
    ll x;
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> k;

    auto cmp = [](entry e1, entry e2) { return e1.x < e2.x;};
    peque <entry, vector<entry>, decltype(cmp)> pq(cmp);

    ll x;
    while (cin >> x){
        pq.push({1, x});
    }

    while(1){
        if (pq.top().n >= k){
            cout << pq.top().x << endl;
            break;
        }
        k -= pq.top().n;
        if (!(pq.top().x & 1)){
            pq.push({pq.top().n * 2, pq.top().x / 2});
        }
        pq.pop();
    }

    return 0;
}