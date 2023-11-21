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

int xa, ya;

int dst(int xb, int yb){
    return abs(xa - xb) + abs(ya - yb); 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, xb, yb;
    cin >> n >> m >> xa >> ya >> xb >> yb;
    xa--;
    ya = m - ya;
    xb--; 
    yb = m - yb;

    int res = dst(xb, yb);
    res = min(res, dst(-n + xb, m - yb - 1));
    res = min(res, dst(n - xb - 1, m + yb));
    res = min(res, dst(n + xb, m - yb - 1));
    res = min(res, dst(n - xb - 1, -m + yb));

    cout << res << endl;
    
    

    return 0;
}