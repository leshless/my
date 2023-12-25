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

    int n;
    cin >> n;

    vector<ldbl> nums;

    for (int i = 0; i < n; i++){
        int m;
        cin >> m;

        for (int j = 0; j < m; j++){
            ldbl x;
            cin >> x;
            nums.push_back(x);
        }
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    ldbl s1 = 0;
    for(int i = 0; i < 2*(n-1); i++){
        s1 += nums[i];
    }
    s1 /= 2;

    ldbl s2 = 0;
    for (int i = 2*(n-1); i < nums.size(); i++){
        s2 += nums[i];
    }
    s2 /= nums.size() - 2*(n-1);


    //cout << fixed << setprecision(10) << s1 + s2 << endl;

    return 0;
}