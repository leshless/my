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

struct entry{
    int x;
    bool t;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <entry> seq(n);
    for (int i = 0; i < n; i++){
        cin >> seq[i].x >> seq[i].t;
    }

    sort(seq.begin(), seq.end(), [](entry a, entry b){return a.x < b.x;});

    int r = 0x7fffffff;
    for (int i = 0; i < n-1; i++){
        if (seq[i].t != seq[i+1].t){
            r = min(r, seq[i+1].x - seq[i].x - 1);
        }
    }

    int res = 0;
    for (int i = 0; i < n-1; i++){
        entry e1 = seq[i];
        entry e2 = seq[i+1];

        if (i == 0 && e1.t){
            res++;
        }

        if (e2.t){
            if (e1.t){
                if (e2.x - e1.x > r){
                    res++;
                }
            }else{
                res++;
            }
        }
    }

    cout << res << "\n";


    return 0;
}