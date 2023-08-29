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
#define peque priority_queue
#define map unordered_map


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    string a;
    cin >> a;

    int c = 0;
    for (auto el : a){
        if (el == '1'){
            c++;
        }
    }

    vector <int> m0(n);
    vector <int> m1(n);
    
    int b0 = 0;
    int b1 = 0;

    for (int i = n-1; i >= 0; i--){
        if (i == n-1){
            m0[i] = 1;
            m1[i] = 1;
        }else{
            m0[i] = (m0[i+1] * 2) % (c + 1);
            m1[i] = (m1[i+1] * 2) % (c - 1);
        }

        if (a[i] == '1'){
            b0 += m0[i];
            b0 %= (c + 1);
            b1 += m0[i];
            b1 %= (c - 1);
        }
    }

    for (int i = 0; i < n; i++){
        
    }

    


    return 0;
}