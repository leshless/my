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

    string alph;
    int k;
    ll n;
    cin >> alph >> k >> n;

    n--;
    int d = alph.size();

    string res;
    while (n > 0){
        res.push_back(alph[n % d]);
        n /= d;
    }
    k -= res.size();

    for (int i = 0; i < k; i++){
        res.push_back(alph[0]);
    }

    reverse(res.begin(), res.end());

    cout << res << endl;

    return 0;
}