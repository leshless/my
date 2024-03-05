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

const ll M = 998244353;
const ll N = 3e5+10;
ll res = 0;
vi g[N];
bool used[N];

ll dfs(int u){
    used[u] = 1;

    ll p = 1, s = 0;
    bool f = 1;
    ForEach(v, g[u]){
        if (!used[v]){
            f = 0;
            ll r = dfs(v);
            
            p *= r;
            p %= M;

            s += r;
            s %= M;
        }
    }

    if (f){
        res += 1;
        return 1;
    }

    res += p + 1;
    return p + 1;
}


void solve(){
    int n;
    cin >> n;

    res = 0;
    vi empty;
    fill_n(g, n, empty);
    fill_n(used, n, 0);

    For(i, 0, n-1){
        int u, v;
        cin >> u >> v;
        u--; v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    cout << (res + 1) % M << endl; 




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