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

struct point{
    ldbl x;
    ldbl y;
};

void print(point p){
    cout << fixed << setprecision(2) <<  p.x << " " << p.y << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <point> points(n);
    for (int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
        points[i].x = roundl(points[i].x * 100) / 100;
        points[i].y = roundl(points[i].y * 100) / 100;
    }

    string bitmask(7, 1);
    bitmask.resize(n, 0);

    while (1){
        vector <point> ps;
        for (int i = 0; i < n; i++){
            if (bitmask[i]){
                ps.push_back(points[i]);
            }
        }
    }

    for (auto p : points){
        print(p);
    }

    return 0;
}