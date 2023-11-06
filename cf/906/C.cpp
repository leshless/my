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

    deque <char> dq;
    int c1 = 0;
    for (int i = 0; i < n; i++){
        c1 += s[i] == '1';
        dq.push_back(s[i]);
    }

    if (c1 != n - c1){
        cout << -1 << endl;
        return;
    }

    vector <int> res;

    int i = 0;
    while(!dq.empty()){
        if (dq.front() == dq.back()){
            if (dq.front() == '1'){
                dq.push_front('1');
                dq.push_front('0');
                res.push_back(0 + i);
            }else{
                dq.push_back('0');
                dq.push_back('1');
                res.push_back(n - i);
            }
            n+=2;
        }else{
            dq.pop_front();
            dq.pop_back();
            i++;
        }
    }

    cout << res.size() << endl;
    for (auto x : res){
        cout << x << " ";
    }
    cout << endl;

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