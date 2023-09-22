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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    int d;
    cin >> n >> d;
        
    int res = 0;
    if (!n){
        res = 1;
    }else{
        while (n > 0){
            if (n % d == 0){
                res++;
            }
            n /= d;
        }
    }

    cout << res << endl;

    return 0;
}