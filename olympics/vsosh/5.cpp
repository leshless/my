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

    vector<set<int>> display{{0, 1, 3, 5, 7, 8}, {2, 3, 7}, {0, 3, 6, 8}, {0, 2, 4, 6}, {1, 3, 4, 7}, {0, 1, 4, 7, 8}, {2, 4, 5, 7, 8}, {0, 2, 5}, {0, 1, 3, 4, 5, 7, 8}, {0, 1, 3, 4, 6}};
   
    vector <bool> number(10, true);
    vector<vector<bool>> table(10, number);

    for (int i = 0; i < 10; i++){
        for (auto a : display[i]){
            table[i][a] = false;
        }
    }

    int n;
    cin >> n;
    
    vector <int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for (int x : nums){
        for (auto &s : table){
            for (auto a : display[x]){
                s[a] = true;
            }
        }
    }

    vector <int> res;
    for (int i = 0; i < 10; i++){
        bool f = 1;
        for (auto a : table[i]){
            f = f && a;
        }

        if (f){
            res.push_back(i);
        }
    }

    for (auto x : res){
        cout << x << " ";
    }
    cout << endl;



    return 0;
}