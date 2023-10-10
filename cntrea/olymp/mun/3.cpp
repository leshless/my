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
    
    ll n;
    cin >> n;

    if (n == 1){
        cout << 1 << endl;
        return 0;
    }

    vector <int> dig;

    for (ll i = 9; i > 0; i--){
        if (i == 1){
            break;
        }
        if (n % i == 0){
            dig.push_back(i);
            n /= i;
            i = 10;
        }
    }
    
    if (n != 1){
        cout << -1 << endl;
    }else{
        reverse(dig.begin(), dig.end());
        for (auto el : dig){
            cout << el;
        }
        cout << endl;
    }
    
    return 0;
}