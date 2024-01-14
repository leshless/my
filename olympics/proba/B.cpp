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

    ll n;
    cin >> n;

    vector <int> nums(n);
    vector <int> ord(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        ord[i] = i;
    }

    sort(ord.begin(), ord.end(), [&](int i, int j){return nums[i] < nums[j];});

    vector <int> left(n);
    stack <int> stl;
    for (int i = 0; i < n; i++){
        int a = nums[i];
        
        while (!stl.empty() && nums[stl.top()] <= a){
            stl.pop();
        }
        if (!stl.empty()){
            left[i] = i - stl.top();
        }else{
            left[i] = i + 1;
        }

        stl.push(i);
    }
    
    vector <int> right(n);
    stack <int> str;

    for (int i = n-1; i >= 0; i--){
        int a = nums[i];
        
        while (!str.empty() && nums[str.top()] <= a){
            str.pop();
        }
        if (!str.empty()){
            right[i] = str.top() - i;
        }else{
            right[i] = n - i;
        }

        str.push(i);
    }

    // for (auto i : left){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto i : right){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto i : ord){
    //     cout << i << " ";
    // }

    int i = 0;
    for (int k = 1; k <= n; k++){
        for (; i < n; i++){
            int j = ord[i];
            int dst = right[j] + left[j] - 1;
            if (dst >= k){
                break;
            }
        }
        cout << nums[ord[i]] << " ";
    }
    
    

    return 0;
}