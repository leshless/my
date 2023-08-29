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
#define map unordered_map

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map <int, int> res;
    map <int, int> ts;
    int t3 = 0;
    int t4 = 0;
    for (int i = 1; i < n+1; i++){
        ts[i] = 0;
    }
    
    for (int i = 0; i < 4 * n; i++){
        int x;
        cin >> x;

        if (res.count(x) == 0 && i >= 2 * n){ 
            int tr3 = t3 - (ts[x] == 3);
            int tr4 = t4 - (ts[x] == 4);
            int d = i - 2 * n + 1;

            int r = min((d / 2), tr4);
            d -= min((d / 2) * 2, tr4 * 2);
            r += min(d, tr3);
            d -= min(d, tr3);

            if (d == 0){
                res[x] = r;
            }else{
                res[x] = -1;
            }
        }

        ts[x]++;
        if (ts[x] == 3){
            t3++;
        }
        if (ts[x] == 4){
            t3--;
            t4++;
        }
    }

    for (int i = 1; i < n+1; i++){
        if (res.count(i) == 0){
            cout << -1 << " ";
        }else{
            cout << res[i] << " ";
        }
    }
    cout << endl;


    return 0;
}