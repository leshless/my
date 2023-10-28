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

    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    map <int, int> div;
    for (int i = 0; i < n; i++){
        int a = nums[i];

        for (int i = 2; i*i <= a; i++){
            if (a % i == 0){
                if (div.count(i) == 0){
                    div[i] = 1;
                }else{
                    div[i] += 1;
                }

                a /= i;
                i--;
            }
        }

        if (a != 1){
            if (div.count(a) == 0){
                div[a] = 1;
            }else{
                div[a] += 1;
            }
        }
    }

    for (auto [a, c] : div){
        if (c % n != 0){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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