#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

const ldbl EPS = 1.11;
string ans;

struct p{
    ldbl x;
    ldbl y;
};

ldbl dst(p p1, p p2){
    ldbl dx = p1.x - p2.x;
    ldbl dy = p1.y - p2.y;
    return sqrtl(dx * dx + dy * dy);
}

bool c1(vector <p> &points){
    ldbl mn = LDBL_MAX;
    ldbl mx = 0;

    for (int i = 0; i < 6; i++){
        ldbl d = dst(points[i], points[(i + 1) % 6]);
        mn = min(mn, d);
        mx = max(mx, d);
    }

    return mx / mn <= EPS;
}

bool c2(vector <p> &points){
    ldbl mn = LDBL_MAX;
    ldbl mx = 0;

    for (int i = 0; i < 3; i++){
        ldbl d = dst(points[i], points[i + 3]);
        mn = min(mn, d);
        mx = max(mx, d);

    }

    return mx / mn <= EPS;
}

bool c3(vector <p> &ps){
    ldbl sx = 0;
    ldbl sy = 0;

    for (int i = 0; i < 6; i++){
        sx += ps[i].x;
        sy += ps[i].y;
    }
    sx = floorl(sx / 6);
    sy = floorl(sy / 6);

    for (int x = sx - 10; x < sx + 10; x++){
        for (int y = sy - 10; y < sy + 10; y++){
            p c;
            c.x = x;
            c.y = y;

            ldbl mn = LDBL_MAX;
            ldbl mx = 0;

            for (int i = 0; i < 6; i++){
                ldbl d = dst(ps[i], c);
                mn = min(mn, d);
                mx = max(mx, d);
            }

            if (mx / mn <= EPS){
                // cout << "center: " << x << " " << y << endl;
                return 1;
            }
        }
    }

    

    return 0;
}


void solve(){
    vector <p> ps(6); 
    for (int i = 0; i < 6; i++){
        cin >> ps[i].x >> ps[i].y;
    }

    ans.push_back((c1(ps) && c2(ps) && c3(ps) ? '1' : '0'));
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        solve();
    }

    cout << ans << endl;

    return 0;
}
    