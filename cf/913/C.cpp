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

    string s;
    cin >> s;

    map <char, int> freq;
    for (auto x : s){
        freq[x]++;
    }

    vector <int> count;
    for (auto [x, c] : freq){
        count.push_back(c);
    }

    sort(count.begin(), count.end(), greater<int>);
    int p = 0;
    for (auto c : count){
        c -= p
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

    return 0;
}