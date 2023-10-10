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

struct ship{
    int x;
    bool t;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <ship> ships;

    int x;
    for (int i = 0; i < n; i ++){
        cin >> x;
        ships.push_back({x, 0});
    }

    for (int i = 0; i < m; i++){
        cin >> x;
        ships.push_back({x, 1});
    }

    sort(ships.begin(), ships.end(), [](ship a, ship b){return a.x < b.x;});

    int res = 0;
    int right = 0;
    for (auto s : ships){
        if (s.t){
            right+=1;
        }else{
            if (right){
                right--;
                res++;
            }else{
                res++;
            }
        }
    }
    res += right;

    cout << res << endl;


    return 0;
}