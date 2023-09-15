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

ll merge(vector <int> &a, int l, int r){
    if (r - l == 1){
        return 0;
    }

    int m = (l + r) / 2;
    ll res = merge(a, l, m) + merge(a, m, r);

    vector <int> la(a.begin() + l, a.begin() + m);
    vector <int> ra(a.begin() + m, a.begin() + r);

    int i = 0;
    int j = 0;

    while (i != la.size() && j != ra.size()){
        if (la[i] < ra[j]){
            a[l + i + j] = la[i];
            i++;
            res += j;
        }else{
            a[l + i + j] = ra[j];
            j++;
        }
    }

    while (i != la.size()){
        a[l + i + j] = la[i];
        i++;
        res += j;
    }

    while (j != ra.size()){
        a[l + i + j] = ra[j];
        j++;
    }

    return res;
}

ll solve(vector <int> a){
    return merge(a, 0, a.size());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll res = solve(a);
    cout << res << "\n";

    for (int i = 0; i < n-1; i++){
        res += n - 1 - 2 * a[i];
        cout << res << "\n";
    }
   
    return 0;
}