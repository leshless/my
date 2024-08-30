#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

typedef long long ll;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

typedef pair <int, int> pi;
typedef pair <ll,ll> pll;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <pi> vpi;
typedef vector <pll> vpll;

template <class T> using peque = priority_queue<T>;
template <class T> using pequeg = priority_queue<T, vector<T>, greater<T>>;

#define map unordered_map
#define ft first 
#define sd second

#define For(i, l, r) for (int i=l; i<r; i++)
#define ForR(i, r, l) for (int i=r; i>l; i--)
#define ForEach(x, vec) for (auto &x : vec)

template <typename T>
void Println(T &x) {cout << x << "\n";}
template <typename T>
void Print(T &x) {cout << x << " ";}
template <typename T>
void Print(vector <T> &vec) {
    for (auto &x : vec){
        cout << x << " ";
    }
    cout << "\n";
}

#define All(vec) vec.begin(), vec.end()
#define Len(vec) int(vec.size())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Sort(vec) sort(vec.begin(), vec.end())
#define Min(vec) *min_element(vec.begin(), vec.end())
#define Max(vec) *max_element(vec.begin(), vec.end())

void timeout(int dur) {
    auto st = high_resolution_clock::now();
    while (true) {
        auto nt = high_resolution_clock::now();
        auto dt = duration_cast<milliseconds>(nt - st).count();
        if (dt >= dur) {
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    int n, m;
    cin >> n >> m;

    vi row(m, INT_MAX);
    vector <vi> mat(n, row);
    For(i, 0, n){
        For(j, 0, m){
            cin >> mat[i][j];
        }
    }

    vector <vi> wdp(n, row);
    vector <vi> hdp(n, row);
    vector <vi> sdp(n, row);

    int res = 0;
    int ri, rj = 0;

    ForR(d, n+m-2, -1){
        For(i, 0, d+1){
            int j = d-i;
            if ((i >= n) || (j >= m)){
                continue;
            }

            if (mat[i][j] == 0){
                hdp[i][j] = 0;
                wdp[i][j] = 0;
                sdp[i][j] = 0;
            }else{
                if (i == n-1){
                    hdp[i][j] = 1;
                }else{
                    hdp[i][j] = hdp[i+1][j] + 1;
                }
    
                if (j == m-1){
                    wdp[i][j] = 1;
                }else{
                    wdp[i][j] = wdp[i][j+1] + 1;
                }

                if ((i == n-1) || (j == m-1)){
                    sdp[i][j] = 1;
                }else{
                    sdp[i][j] = min(sdp[i+1][j+1], min(hdp[i+1][j], wdp[i][j+1])) + 1;
                }
            }

            if (sdp[i][j] >= res){
                res = sdp[i][j];
                ri = i+1;
                rj = j+1;
            }
        }
    }

    // cout << endl;
    // For(i, 0, n){
    //     Print(wdp[i]);
    // }
    // cout << endl;
    // For(i, 0, n){
    //     Print(hdp[i]);
    // }cout << endl;
    // For(i, 0, n){
    //     Print(sdp[i]);
    // }

    cout << res << endl;
    cout << ri << " " << rj << endl;
    
    return 0;
}