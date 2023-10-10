#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double

const ldbl EPS = 1e-5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string dl = "/";

    string cos;
    cin >> cos;

    ll xc = stoll(cos.substr(0, cos.find(dl)));
    ll xz = stoll(cos.substr(cos.find(dl) + 1));


    string sin;
    cin >> sin;

    ll yc = stoll(sin.substr(0, sin.find(dl)));
    ll yz = stoll(sin.substr(sin.find(dl) + 1));
    
    cout << (xc * (lcm(xz, yz) / xz)) / gcd(xc, yc) << " " << (yc * (lcm(xz, yz) / yz)) / gcd(xc, yc);


    return 0;
}