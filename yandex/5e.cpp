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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a;
    cin >> a;

    int n = a.size();
    int res = n / 2;

    int i, j;
    if (n & 1){
        res++;
        i = n / 2 - 1;
        j = n / 2 + 1;
    }else{  
        i = n / 2 - 1;
        j = n / 2;
    }

    while (i != -1){
        if (a[i] != a[i+1] || a[j] != a[j-1]){
            break;
        }

        res++;
        i--;
        j++;
    }


    cout << res << endl;

    return 0;
}