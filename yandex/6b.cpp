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
    ll a;
    ll b;
    ll c;
    ll p;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <entry> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i].a >> nums[i].b >> nums[i].c;
    }

    ll res = -1;

    for (int s = 0; s < 8; s++){
        int sa = (s & 1 ? 1 : -1);
        int sb = ((s >> 1) & 1 ? 1 : -1);
        int sc = ((s >> 2) & 1 ? 1 : -1);

        for (auto &e : nums){
            e.p = e.a * sa + e.b * sb + e.c * sc; 
        }

        sort(nums.begin(), nums.end(), [](entry e1, entry e2){return e1.p > e2.p;});
        ll ra = 0;
        ll rb = 0;
        ll rc = 0;

        for (int i = 0; i < m; i++){
            ra += nums[i].a;
            rb += nums[i].b;
            rc += nums[i].c;
        }

        res = max(res, abs(ra) + abs(rb) + abs(rc));
    }

    cout << res << endl;

    return 0;
}