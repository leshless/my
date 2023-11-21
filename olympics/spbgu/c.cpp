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

    map <char, int> shift;
    for (int i = m-2; i >= 0; i--){
        char x = p[i];
        if (shift.count(x) == 0){
            shift[x] = m-i-1;
        }
    }
    if (shift.count(p[m-1]) == 0){
        shift[p[m-1]] = m;
    }

    int i = m-1;
    int res = 0;

    while (i-m+1 < n){
        char x = s1[i];
        int k = i;
        bool f = 1;

        for (int j = m-1; j >= 0; j--){
            if (p[j] != s1[k]){
                f = 0;
                break;
            }else{
                k--;
            }
        }

        if (f){
            res++;
            i++;
            // cout << k+1 << " ";
        }else{
            if (shift.count(x) == 0){
                i += m;
            }else{
                i += shift[x];
            }
        }
    }

    cout << res << endl;


    return 0;
}