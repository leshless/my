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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> k;

    peque <ll> pq;

    ll x;
    while (cin >> x){
        pq.push(x);
    }

    ll i = 0;
    while (++i){
        if (i == k){
            cout << pq.top() << endl;
            break;
        }

        if (!(pq.top() & 1)){
            pq.push(pq.top() / 2);
            pq.push(pq.top() / 2);
        }

        pq.pop();
    }


    return 0;
}