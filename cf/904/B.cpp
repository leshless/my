#pragma GCC optimize("O3")

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

void solve(){
    int n;
    string s;
    cin >> n >> s;

    reverse(s.begin(), s.end());

    queue <int> zeros;
    for (int i = 0; i < n; i++){
        if (s[i] == '0'){
            zeros.push(i);
        }
    }
    for (int i = 0; i < n; i++){
        if (zeros.front() == i){
            zeros.pop();
        }else{
            break;
        }
    }

    vector <ll> res(n);
    bool c = 0;
    for (int i = 0; i <= n; i++){
        if (i){
            if (!c){
                res[i-1] = 0;
            }else if (zeros.empty()){
                res[i-1] = -1;
            }else{
                res[i-1] = zeros.front() - i + 1;
                if (i > 1){
                    res[i-1] += res[i-2];
                }
                zeros.pop();
            }
        }        
        
        if (s[i] == '1'){
            c = 1;
        }
    }

    for (int el : res){
        cout << el << " ";
    }
    cout << endl;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}