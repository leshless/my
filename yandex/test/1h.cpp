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

int foo(int a){
    if (a == 0){
        return 0;
    }

    int b = a;
    int c = 0;
    for (int i = 0; i < 32; i++){
        c += (b & 1);
        b >>= 1;
    }
    
    return foo(a % c) + 1;
}

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

    int mod0 = c + 1;
    int mod1 = (c - 1 ? c - 1 : 1);
    
    int b0 = 0;
    int b1 = 0;

    for (int i = n-1; i >= 0; i--){
        if (i == n-1){
            m0[i] = 1;
            m1[i] = 1;
        }else{
            m0[i] = (m0[i+1] * 2) % mod0;
            m1[i] = (m1[i+1] * 2) % mod1;
        }

        if (a[i] == '1'){
            b0 += m0[i];
            b0 %= mod0;
            b1 += m1[i];
            b1 %= mod1;
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i] == '1'){
            int next = b1 - m1[i];
            if (next < 0){
                next += mod1;
            }
            cout << foo(next) + !(a[i] == '1' && c == 1) << "\n";
        }else{
            int next = b0 + m0[i];
            next %= mod0;
            cout << foo(next) + 1 << "\n";
        }
    }

    


    return 0;
}