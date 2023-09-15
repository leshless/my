#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define peque priority_queue

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int s1 = max(c, d) + 2;
    int s2 = max(a, b) + 2;
    int s3 = min(a + c, b + d) + 2;
    int mn = min({s1, s2, s3});

    int m, n;

    if (s2 == mn){
        m = max(a, b) + 1; 
        n = 1;
    }
    if (s3 == mn){
        if (a + c < b + d){
            m = a + 1;
            n = c + 1;
        }else if(a + c > b + d){
            m = b + 1;
            n = d + 1;
        }else{
            if (a < b){
                m = a + 1;
                n = c + 1;
            }else{
                m = b + 1;
                n = d + 1;
            }
        }
    }
    if (s1 == mn){
        m = 1;
        n = max(c, d) + 1;
    }

    if (c == 0){
        m = a + 1;
        n = 1;
    }
    if (d == 0){
        m = b + 1;
        n = 1;
    }
    if (a == 0){
        m = 1;
        n = c + 1;
    }
    if (b == 0){
        m = 1;
        n = d + 1;
    }

    cout << m << " " << n << endl;

    return 0;
}