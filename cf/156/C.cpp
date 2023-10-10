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

string ans;

void solve(){
    string s;
    ll p;
    cin >> s >> p;

    int n = s.size();

    stack <pair <char, int>> st;
    vector <int> ord(n);

    int c = 0;
    for (int i = 0; i < n; i++){
        while (!st.empty()){
            if (st.top().first > s[i]){
                ord[st.top().second] = c;
                c++;
                st.pop();
            }else{
                break;
            }
        }
        st.push({s[i], i});
    }

    while (!st.empty()){
        ord[st.top().second] = c;
        c++;
        st.pop();
    }

    // for (auto el : ord){    
    //     cout << el << " ";
    // }
    // cout << endl;

    c = 0;
    while (p > n){
        p-=n;
        n--;
        c++;
    }

    // cout << p << endl;
    
    int c1 = 0;
    for (int i = 0; i < ord.size(); i++){
        if (ord[i] >= c){
            c1++;
        }
        if (c1 == p){
            ans.push_back(s[i]);
            return;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        solve();
    }

    cout << ans;

    return 0;
}