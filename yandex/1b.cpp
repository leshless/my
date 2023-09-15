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

    int n;
    ldbl a, b;
    cin >> n >> a >> b;

    vector <int> time(n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;

        string h(s.begin(), s.begin() + 2);
        string m(s.begin() + 3, s.end());

        time[i] = stoi(h) * 60 + stoi(m);
    }

    time.push_back(23 * 60 + 59);

    ldbl res = 100;

    for (int i = 0; i < n; i++){
        int d = time[i+1] - time[i];

        if (i & 1){
            res += (100 / b) * d;
            res = (res > 100 ? 100 : res);
        }else{
            res -= (100 / a) * d;
            res = (res < 0 ? 0 : res);
        }
    }

    cout << fixed << setprecision(5) << res;

    return 0;
}