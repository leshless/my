#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

int foo(int s, int t){
    if (s > t){
        return 0;
    }
    if (s == t){
        return 1;
    }

    return foo(s+1, t) + foo(s*3/2, t) + foo(s*2, t);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << foo(10, 51) * foo(51, 5094) << endl;

    return 0;
}