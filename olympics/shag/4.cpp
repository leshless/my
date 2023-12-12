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

    vector <ll> row(m);
    vector <vector<ll>> mat(n, row);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    ll res = LLONG_MIN;
    int ri, rj;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ll sum = 0;
            int step = 0;
            int k = i;
            int l = j;

            while(1){
                sum += mat[k][l];
                if (step == 1){
                    k--;
                }else{
                    l++;
                }

                step = (step + 1) % 3;
                if ((k == -1) || (l == m)){
                    break;
                }
            }

            if (sum > res){
                res = sum;
                ri = i;
                rj = j;
            }
        }
    }

    cout << res << endl;
    cout << ri+1 << " " << rj+1 << endl;

    

    return 0;
}