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

    int n, m;
    cin >> n >> m;

    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }


    sort(nums.begin(), nums.end(), [&](int a, int b){return a % m < b % m;});
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());

    map <int, int> seg;
    for (int x : nums){
        seg[x / m]++;
    }

    int r = mx / m;
    int l = mn / m;
    if (seg.size() >= r - l + 1){
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n;){
        int cur = nums[i] % m + 1;
        if (cur == m){
            break;
        }
        // cout << cur << ": ";

        while ((i < n) && (nums[i] % m + 1 == cur)){
            // cout << nums[i] << " ";
            int s = nums[i] / m;
            seg[s]--;
            if (!seg[s]){
                seg.erase(s);
            }
            seg[s-1]++;
            i++;
        }
        // cout << endl;

        int r = (cur >= mx % m + 1 ? mx / m - 1 : mx / m);
        int l = (cur >= mn % m + 1 ? mn / m - 1 : mn / m);

        if (seg.size() >= r - l + 1){
            cout << cur << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}