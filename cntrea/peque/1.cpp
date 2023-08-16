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

    int k;
    cin >> k;

    peque <ll, vector<ll>, greater<ll>> pq;

    ll x;
    while (cin >> x){
        pq.push(x);
        if (pq.size() > k){
            pq.pop();
        }
        if (pq.size() < k){
            cout << "NO\n";
        }else{
            cout << pq.top() << "\n";
        }

    }


    return 0;
}