#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double

const ldbl EPS = 1e-17;
struct point{
    ldbl x;
    ldbl y;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    point p, p1, p2;
    cin >> p.x >> p.y >> p1.x >> p1.y >> p2.x >> p2.y;

    if ((p.x == p1.x && p.y == p1.y) || (p.x == p2.x && p.y == p2.y)){
        cout << "YES";
        return 0;   
    }

    if (p1.x == p2.x && p1.y == p2.y){
        cout << "NO";
        return 0;
    }

    if (abs(atan2l(p2.y - p1.y, p2.x - p1.x) - atan2l(p2.y - p.y, p2.x - p.x)) < EPS 
    && abs(atan2l(p1.y - p2.y, p1.x - p2.x) - atan2l(p1.y - p.y, p1.x - p.x)) < EPS){
        cout << "YES";   
    }else{
        cout << "NO";
    }



    return 0;
}