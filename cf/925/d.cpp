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

void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    vi nums(n);
    For(i, 0, n){
        cin >> nums[i];
    }

    map <int, map<int, int>> table;
    ll res = 0;
    For(i, 0, n){
        int r1 = nums[i] % y;
        int r2 = nums[i] % x;

        if (table.count(r1) == 0){
            map <int, int> empty;
            table[r1] = empty;
        }

        if (table[r1].count((x - r2) % x)){
            res += table[r1][(x - r2) % x];
        }

        if (table[r1].count(r2)){
            table[r1][r2]++;
        }else{
            table[r1][r2] = 1;
        }
    }

    cout << res << endl;


    return;
}


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}