#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double

const int N = 200;

struct point{
    int x;
    int y;
};

point mat[2*N+1][2*N+1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    int x1, y1;
    cin >> x1 >> y1;

    int x2, y2;
    cin >> x2 >> y2;


    for (int x = -k; x <= k; x++){
        for (int y = -k; y <= k; y++){
            mat[x+N][y+N].x = (abs(x) & 1 ? n - x2 : x2) + n * x;
            mat[x+N][y+N].y = (abs(y) & 1 ? m - y2 : y2) + m * y;
        }
    }

    bool f = (x1 < x2);

    // for (int i = -2; i <= 2; i++){
    //     cout << mat[N][i+N].y << " ";
    // }


    int res = -1;
    for (int s = k; s >= 0; s--){
        for (int x = 0; x <= s; x++){
            int y = s - x;


            point tar = {-x * n, -y * m};
            int c = 0;
            int dy = tar.y - y1;
            int dx = tar.x - x1;

            for (int i = -x; i <= 0; i++){
                for (int j = -y; j <= 0; j++){
                    if ((dx * mat[i+N][j+N].y - dy * mat[i+N][j+N].x == dx * y1 - dy * x1) && (!(i == 0 && j == 0) || !f)){
                        c++;
                    }
                }
            }
            if (c == 1){
                // cout << tar.x << " " << tar.y << endl;
                res = s;
                goto next;
            }


            tar = {-x * n, (y + 1) * m};
            c = 0;
            dy = tar.y - y1;
            dx = tar.x - x1;

            for (int i = -x; i <= 0; i++){
                for (int j = 0; j <= y; j++){
                    if ((dx * mat[i+N][j+N].y - dy * mat[i+N][j+N].x == dx * y1 - dy * x1) && (!(i == 0 && j == 0) || !f)){
                        c++;
                    }
                }
            }
            if (c == 1){
                // cout << tar.x << " " << tar.y << endl;
                res = s;
                goto next;
            }


            tar = {(x + 1) * n, -y * m};
            c = 0;
            dy = tar.y - y1;
            dx = tar.x - x1;

            for (int i = 0; i <= x; i++){
                for (int j = -y; j <= 0; j++){
                    if ((dx * mat[i+N][j+N].y - dy * mat[i+N][j+N].x == dx * y1 - dy * x1 && (!(i == 0 && j == 0) || f))){
                        c++;
                    }
                }
            }
            if (c == 1){
                // cout << tar.x << " " << tar.y << endl;
                res = s;
                goto next;
            }



            tar = {(x + 1) * n, (y + 1) * m};
            c = 0;
            dy = tar.y - y1;
            dx = tar.x - x1;

            for (int i = 0; i <= x; i++){
                for (int j = 0; j <= y; j++){
                    if ((dx * mat[i+N][j+N].y - dy * mat[i+N][j+N].x == dx * y1 - dy * x1) && (!(i == 0 && j == 0) || f)){
                        c++;
                    }
                }
            }
            if (c == 1){
                // cout << tar.x << " " << tar.y << endl;
                res = s;
                goto next;
            }
        }

        next:
            continue;
    }

    cout << res << "\n";

    return 0;
}