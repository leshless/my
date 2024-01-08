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
    string s;
    cin >> s;

    int n = s.size();

    reverse(s.begin(), s.end());

    int b = 0;
    int B = 0;

    string res;
    for (int i = 0; i < n; i++){
        char x = s[i];
        if (x == 'b'){
            b++;
        }else if (x == 'B'){
            B++;
        }else if ((x >= 'a') && (x <= 'z')){
            if (b){
                b--;
            }else{
                res.push_back(x);
            }
        }else{
            if (B){
                B--;
            }else{
                res.push_back(x);
            }
        }
    }

    reverse(res.begin(), res.end());

    cout << res << endl;


    

    return;
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