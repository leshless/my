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

vector<int> preff(string s) {
    int n = s.size();
    vector<int> p(n, 0);

    for (int i = 1; i < n; i++) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0){
            cur = p[cur - 1];
        }
        if (s[i] == s[cur]){
            p[i] = cur + 1;
        }
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, p;
    cin >> s >> p;

    int n = s.size();
    int m = p.size();
    int k = 1 + (m - 1) / n + ((m - 1) % n != 0);
    
    string s1(n*k, 'x');

    for (int i = 0; i < n; i++){
        char x = s[i];
        for (int j = 0; j < k; j++){
            s1[n*j + i] = x;
        }
    }
    // cout << s1 << endl;

    auto pref = preff(p);
    // for (int x : pref){
    //     cout << x << " ";
    // }
    // cout << endl;

    int res = 0;
    int i = 0;
    int j = 0;
    while(i < s1.size() && i - j < n){
        if (p[j] == s1[i]){
            i++;
            j++;
            if (j == m){
                res++;
                j = pref[m-1];
            }
        }else{
            if (j){
                j = pref[j-1];
            }else{
                i++;
            }
        }
    }

    cout << res << endl;



    return 0;
}