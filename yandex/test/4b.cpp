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

    vector <int> a(n);
    vector <int> b(n);
    map <int, int> ban;

    for (int i = 0; i < n; i++){
        ban[i] = false;
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    int res = 0;

    int i = 0;
    int j = 0;
    while (1){
        if (ban[a[i]]){
            i++;
        }else{
            if (a[i] != b[j]){
                res++;
                ban[b[j]] = 1;
                j++;
            }else{
                i++;
                j++;
            }
        }
        if (i == n || j == n){
            break;
        }
    }

    cout << res << endl;




    return 0;
}