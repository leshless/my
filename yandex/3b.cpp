#pragma GCC optimize("O3,unroll-loops")

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    peque <int, vector<int>, greater<int>> g;
    peque <int, vector<int>, greater<int>> r;

    for (int i = 0; i < a; i++){
        int n;
        cin >> n;

        g.push(n);
        if (g.size() > x){
            g.pop();
        }
    }

    for (int i = 0; i < b; i++){
        int n;
        cin >> n;

        r.push(n);
        if (r.size() > y){
            r.pop();
        }
    }

    for (int i = 0; i < c; i++){
        int n;
        cin >> n;
    
        if (g.top() < r.top()){
            g.push(n);
            g.pop();
        }else{
            r.push(n);
            r.pop();
        }
    }

    ll res = 0;
    for (int i = 0; i < x; i++){
        res += g.top();
        g.pop();
    }
    for (int i = 0; i < y; i++){
        res += r.top();
        r.pop();
    }

    cout << res << endl;



    return 0;
}