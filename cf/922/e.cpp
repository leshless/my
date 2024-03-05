#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef __int128_t int128;
 
typedef pair <int, int> pi;
typedef pair <ll,ll> pll;
 
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <pi> vpi;
typedef vector <pll> vpll;
 
template <class T> using peque = priority_queue<T>;
template <class T> using pequeg = priority_queue<T, vector<T>, greater<T>>;
 
#define ft first 
#define sd second
 
#define For(i, l, r) for (int i=l; i<r; ++i)
#define ForR(i, l, r) for (int i=r-1; i>=l; --i)
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

const int128 MAX = 1e18;

void solve(){
    int h, w, x1, y1, x2, y2;
    cin >> h >> w >> y1 >> x1 >> y2 >> x2;
    y1 = h - y1 + 1;
    y2 = h - y2 + 1;

    if (y2 >= y1){
        cout << "DRAW" << endl;
        return;
    }

    int t = y1 - y2;
    if (t & 1){
        if (abs(x1 - x2) <= 1){
            cout << "ALICE" << endl;
            return;
        }

        if (x1 < x2){
            cout << ((w - x1) <= t/2+1 ? "ALICE" : "DRAW") << endl;
        }else{
            cout << ((x1 - 1) <= t/2+1 ? "ALICE" : "DRAW") << endl;
        }
    }else{
        if (abs(x1 - x2) == 0){
            cout << "BOB" << endl;
            return;
        }

        if (x1 < x2){
            cout << ((x2 - 1) <= t/2 ? "BOB" : "DRAW") << endl;
        }else{
            cout << ((w - x2) <= t/2 ? "BOB" : "DRAW") << endl;
        }
    }



    return;
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