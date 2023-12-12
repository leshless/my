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


struct ev{
    int s;
    int e;
};
auto cmp = [](ev e1, ev e2){return e1.s < e2.s;};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector <ev> evs;
    
    int s, e;
    while (cin >> s >> e){
        evs.push_back(ev{s, e+15});
    }
    int n = evs.size();

    vector <ev> ord;
    for (int i = 0; i < n; i++){
        ev e1 = evs[i];
        bool f = 1;
        for (int j = 0; j < n; j++){
            if (j != i){
                ev e2 = evs[j];
                if ((e1.s <= e2.s) && (e2.e <= e1.e)){
                    f = 0;
                    break;
                }
            }
        }
        if (f){
            ord.push_back(e1);
        }
    }
    sort(ord.begin(), ord.end(), cmp);
    n = ord.size();

    int res = 0;
    int p = 0;
    int pp = 0;

    for (auto e : ord){
        if (e.s >= p){
            res++;
            pp = p;
            p = e.e;
        }
    }

    int last = (res == 1 ? 0 : ord[n-1].s - pp + 15);
    cout << res << " " << last;



    return 0;
}