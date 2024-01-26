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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int res = 0;
    for (int i = 0; i < 7; i++){
        int x;
        cin >> x;
        res += (x >= 90);
    }

    cout << res << endl;

    return 0;
}