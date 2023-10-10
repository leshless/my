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

ldbl dist(ldbl x1, ldbl y1, ldbl x2, ldbl y2){
    ldbl dx = abs(x1 - x2);
    ldbl dy = abs(y1 - y2);
    return sqrtl(dx*dx + dy*dy);
}

void solve(){
    ldbl px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    bool s;
    bool e;

    ldbl res = 0;
    if (dist(ax, ay, 0, 0) < dist(bx, by, 0, 0)){
        res = max(res, dist(ax, ay, 0, 0));
        s = 0;
    }else{
        res = max(res, dist(bx, by, 0, 0));
        s = 1;
    }

    if (dist(ax, ay, px, py) < dist(bx, by, px, py)){
        res = max(res, dist(ax, ay, px, py));
        e = 0;
    }else{
        res = max(res, dist(bx, by, px, py));
        e = 1;
    }

    if (s != e){
        res = max(res, dist(ax, ay, bx, by) / 2);
    }

    cout << fixed << setprecision(10) << res << endl;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}