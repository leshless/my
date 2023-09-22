#pragma GCC optimize("O3")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map <char, int> al;
    for (int i = 0; i < 36; i++){
        al[a[i]] = i;
    }

    string n;
    ull d;
    cin >> n >> d;

    ull c = n.size() - 1;
    ull b = 0;
    for (char r : n){
        b += al[r] * pow(d, c);
        c--;     
    }

    ull l = 1;
    ull r = 1ull << 32;
    while (r - l > 1){
        ull m = (l >> 1) + (r >> 1);

        if (m * m <= b){
            l = m;
        }else{
            r = m;
        }
    }

    cout << (l * l == b ? "YES" : "NO") << endl;

    return 0;
}