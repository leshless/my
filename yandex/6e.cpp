#pragma GCC optimize("O3,unroll-loops")

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

struct entry{
    int a;
    int b;
};

void solve(){
    int n, m;
    cin >> n >> m;

    vector <entry> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i].a >> nums[i].b;
    }

    sort(nums.begin(), nums.end(), [](entry e1, entry e2){return (e1.b - e1.a) > (e2.b - e2.a);});

    ll res = 0;

    int i = 0;
    while (n-i != m && i != n){
        entry e = nums[i];

        if (e.a >= e.b){
            break;
        }


        res += e.b;
        i++;
        m-=2;
    }

    if (i < n-1){
        while (i != n){
            entry e = nums[i];
            res += e.a;
            i++;
        }
    }else if(i == n-1){
        entry e = nums[i];
        int tail = e.b;

        for (int j = 0; j < n-1; j++){
            entry e1 = nums[j];
            tail = max(tail, e.a + e1.a - e1.b);
        }

        res += tail;
    }

    cout << res << endl;

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