#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long q;
    cin >> q;

    while (q % 2 == 0){
        q /= 2;
    }
    
    long long res = 1;
    for (long long i = 3; i <= q; i++){
        if (q % i == 0){
            int d = 0;
            while (q % i == 0){
                q /= i;
                d++;
            }
            d = 2*d + 1;
            res *= d;
        }
    }

    cout << res << endl;

    return 0;
}