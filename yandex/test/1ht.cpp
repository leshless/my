#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbl double
#define ldbl long double

int foo(ull a){
    if (a == 0){
        return 0;
    }

    ull b = a;
    int c = 0;
    for (int i = 0; i < 33; i++){
        c += (b & 1);
        b >>= 1;
    }
    
    return foo(a % c) + 1;
}

ull btoull(bitset<33> a){
    ull b = 0;
    for (int i = 0; i < 33; i++){
        b += pow(2, 33 - i - 1) * a[i];
    }
    return b;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    

    bitset <33> a;

    for (int i = 0; i < 33; i++){
        a[i] = rand() % 2;
    }

    cout << 33 << endl;
    for (int i = 0; i < 33; i++){
        cout << a[i];
    }
    cout << endl;

    for (int i = 0; i < 33; i++){
        a[i] = !a[i];
        ull b = btoull(a);
        cout << foo(b) << " ";
        for (int i = 0; i < 33; i++){
            cout << a[i];
        }
        cout << " " << b << endl;
        a[i] = !a[i];
    }

    return 0;
}