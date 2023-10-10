#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector <int> a;
    int x;
    while (cin >> x){
        a.push_back(x);
    }

    int n = a.size();
    
    vector <int> sufs(n, 0);
    vector <int> prefs(n-1, 0);

    sufs[n-1] = a[n-1]-(n-1);
    for (int i = n-2; i >= 0; i--){
        sufs[i] = max(sufs[i+1], a[i]-i);
    }
    
    prefs[0] = a[0] - n;
    for (int i = 1; i+1 < n; i++){
        prefs[i] = max(prefs[i-1], a[i]-n-i);
    }
    
    int res = max(sufs[0], sufs[n-1]);
    for (int i = 1; i+1 < n; i++){
        res = min(res, max(sufs[i], prefs[i-1]) + i);
    }


    cout << res << endl;
        



    return 0;
}