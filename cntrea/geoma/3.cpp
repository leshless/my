#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double

const ll EPS = 1e-17;
struct point{
    ll x;
    ll y;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector <point> points;
    ll x, y;
    while (cin >> x >> y){
        points.push_back({x, y});
    }

    ll a = 0;
    for (int i = 0; i < points.size(); i++){
        auto p1 = points[i];
        auto p2 = (i == points.size() - 1 ? points[0] : points[i+1]);

        a += p2.x * p1.y - p1.x * p2.y;
    }

    a = abs(a);


    if (a & 1){
        cout << a << "/2" << endl;
    }else{
        cout << a/2 << endl;
    }

    



    return 0;
}