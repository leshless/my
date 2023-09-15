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

struct entry{
    int x1;
    int y1;
    int x2;
    int y2;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> row(m, 0);
    vector <vector<int>> mat(n, row);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    int res1 = 0;
    vector <entry> res2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] & 1){
                if (j == m-1 && i == n-1){
                    continue;
                }

                res1++;
                mat[i][j]--;
                if(j == m-1){
                    mat[i+1][j]++;
                    res2.push_back({i, j, i+1, j});
                }else{
                    mat[i][j+1]++;
                    res2.push_back({i, j, i, j+1});
                }
            }
        }
    }

    cout << res1 << "\n";
    for (auto e : res2){
        cout << e.x1+1 << " " << e.y1+1 << " " << e.x2+1 << " " << e.y2+1 << "\n";
    }


    return 0;
}