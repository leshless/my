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

vector <string> permutations(string s){
    int n = s.size();
    vector <string> res;
    if (n == 0){
        res.push_back("");
        return res;
    }

    for (int i = 0; i < n; i++){
        string nalph;
        nalph.insert(nalph.end(), s.begin(), s.begin() + i);
        nalph.insert(nalph.end(), s.begin() + i + 1, s.end());

        auto perms = permutations(nalph);
        for (auto &next : perms){
            next.push_back(s[i]);
            res.push_back(next);
        }
    }

    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    auto res = permutations(s);
    sort(res.begin(), res.end());

    for (auto p : res){
        cout << p << endl;
    }


    return 0;
}