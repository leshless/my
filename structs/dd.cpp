#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double

struct Point{
    int x, y
};

struct Treap{
    int x, y;
    Treap *l, *r;
};

Treap build(vector <int> a){
    vector <Point> b;
    for (auto x : a){
        b.push_back({x, rand()});
    }

    
}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}