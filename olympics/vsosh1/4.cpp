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

    int n;
    cin >> n;

    vector <int> res;
    while (n != 1){
        res.push_back(n / 2 + (n % 2));
        n /= 2;
    }
    res.push_back(1);

    for (int x : res){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}