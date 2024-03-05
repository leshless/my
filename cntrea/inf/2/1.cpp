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

    string s;
    cin >> s;

    vector <string> ans;

    vector <bool> b{0, 1};
    for (auto x : b){
        for (auto y : b){
            for (auto z : b){
                for (auto w : b){
                    if (!(((x <= y) && (y <= w)) || (z == (x || y)))){
                        string res;
                        for (char el : s){
                            switch (el){
                            case 'x':
                                res.push_back('0' + x);
                                break;
                            case 'y':
                                res.push_back('0' + y);
                                break;
                            case 'z':
                                res.push_back('0' + z);
                                break;
                            case 'w':
                                res.push_back('0' + w);
                                break;
                            }
                        }
                        ans.push_back(res);
                    }
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (string s : ans){
        cout << s << endl;
    }

    return 0;
}