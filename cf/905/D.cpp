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
    cin >> n;

    peque <int> lmx;
    peque <int, vector <int>, greater<int>> rmn;

    peque <int> ldel;
    peque <int, vector <int>, greater<int>> rdel;

    for (int i = 0; i < n; i++){
        char t;
        int l, r;
        cin >> t >> l >> r;

        if (t == '-'){
            ldel.push(l);
            rdel.push(r);

            while (!ldel.empty() && !lmx.empty()){
                if (ldel.top() == lmx.top()){
                    ldel.pop();
                    lmx.pop();
                }else{
                    break;
                }
            }
            while (!rdel.empty() && !rmn.empty()){
                if (rdel.top() == rmn.top()){
                    rdel.pop();
                    rmn.pop();
                }else{
                    break;
                }
            }
        }else{
            lmx.push(l);
            rmn.push(r);
        }

        if (lmx.top() > rmn.top()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    solve();

    return 0;
}