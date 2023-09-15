#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define _USE_MATH_DEFINES
#define ll long long
#define dbl double
#define ldbl long double

const ldbl EPS = 1e-6;
struct point{
    ldbl x;
    ldbl y;
};

ldbl topi(ldbl arc){
    if (arc > M_PI){
        arc -= M_PI * 2;
    }

    if (arc < -M_PI){
        arc += M_PI * 2;
    }

    return arc;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    point p;
    cin >> p.x >> p.y;

    vector <point> points;
    ldbl x, y;
    while (cin >> x >> y){
        if (p.x == x && p.y == y){
            cout << "BOUNDARY\n";
            return 0;
        }
        points.push_back({x, y});
    }

    ldbl sum = 0.0;
    for (int i = 0; i < points.size(); i++){
        auto p1 = points[i];
        auto p2 = (i == points.size()-1 ? points[0] : points[i+1]);

        ldbl arc = topi(atan2l(p1.y - p.y, p1.x - p.x) - atan2l(p2.y - p.y, p2.x - p.x));
        if (abs(abs(arc) - M_PI) < EPS){
            cout << "BOUNDARY\n";
            return 0;
        }
        sum += arc;
    }


    if (abs(abs(sum) - 2 * M_PI) < EPS){
        cout << "INSIDE\n";
    }else{
        cout << "OUTSIDE\n";
    }

 

    return 0;
}