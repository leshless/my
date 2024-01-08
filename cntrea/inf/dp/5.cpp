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
    int id;
    int time;
    bool type;
};
auto cmp = [](ev e1, ev e2){
    if (e1.time < e2.time){
        return true;
    }else if (e1.time > e2.time){
        return false;
    }else{
        return !e1.type;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> k;

    vector <ev> ord;
    int s, e;
    int id = 0;

    while (cin >> s >> e){
        ord.push_back(ev{id, s, 0});
        ord.push_back(ev{id, e, 1});
        id++;
    }
    sort(ord.begin(), ord.end(), cmp);

    peque <int, vector<int>, greater<int>> free;
    for (ll i = 1; i <= k; i++){
        free.push(i);
    }

    map <int, int> stored;
    int res = 0;
    int last;

    for (ev e : ord){
        if (!e.type){
            if (!free.empty()){
                int n = free.top();
                free.pop();
                stored[e.id] = n;
                res++;
                last = n;
            }
        }else{
            if (stored.count(e.id) != 0){
                int n = stored[e.id];
                stored.erase(e.id);
                free.push(n);
            }
        }
    }


    cout << res << " " << last << endl;

    return 0;
}