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

    string alph = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map <char, int> val;
    for (int i = 0; i < alph.size(); i++){
        val[alph[i]] = i;
    }

    int d;
    string a, b;
    cin >> a >> b >> d;

    string res;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int c = 0;
    while (i != -1 && j != -1){
        int s = val[a[i]] + val[b[j]] + c;
        res.push_back(alph[s % d]);
        c = s / d;

        i--; j--;
    }

    while (i != -1){
        int s = val[a[i]] + c;
        res.push_back(alph[s % d]);
        c = s / d;

        i--;
    }

    while (j != -1){
        int s = val[b[j]] + c;
        res.push_back(alph[s % d]);
        c = s / d;

        j--;
    }

    if (c != 0){
        res.push_back(alph[c]);
    }

    reverse(res.begin(), res.end());

    cout << res << endl;

    return 0;
}