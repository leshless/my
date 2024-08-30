#pragma GCC optimize("O3")

#include <bits/stdc++.h>

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
template <typename K, typename V>
void Print(map <K, V> &m) {
    for (auto &[k, v] : m){
        cout << k << ":" << v << " ";
    }
    cout << "\n";
}

#define All(vec) vec.begin(), vec.end()
#define Len(vec) int(vec.size())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Sort(vec) sort(vec.begin(), vec.end())
#define Min(vec) *min_element(vec.begin(), vec.end())
#define Max(vec) *max_element(vec.begin(), vec.end())

vector <vi> g;
vector <bool> used;
vector <int> low;
vector <int> dst;
vector <bool> good;

void dfs_low(int u, int p, int d){
    dst[u] = d;
    low[u] = d;
    used[u] = 1;

    ForEach(v, g[u]){
        if (v == p){
            continue;
        }
        if (used[v]){
            low[u] = min(low[u], dst[v]);
        }else{
            dfs_low(v, u, d+1);
            low[u] = min(low[u], low[v]);
        }

        good[u] = good[u] && (low[v] > dst[u]);
    }

}

int dfs_good(int u){
    used[u] = 1;
    int res = 0;

    ForEach(v, g[u]){
        if (!used[v] && (good[u] || good[v])){
            res += dfs_good(v);
        }
    }

    return res + 1;
}

void solve(){
    int n, m;
    cin >> n >> m;

    g.resize(n);
    used.resize(n, 0);
    low.resize(n, 0);
    dst.resize(n, 0);
    good.resize(n, 1);

    For(i, 0, m){
        int u, v;
        cin >> u >> v;
        u--; v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    For(u, 0, n){
        if (!used[u]){
            dfs_low(u, -1, 0);
        }
    }
    used.assign(n, 0);


    ll res = 0;
    For(u, 0, n){
        if (!used[u]){
            ll cnt = dfs_good(u);
            res += cnt * (cnt - 1) / 2;
        }
    }

    ll con = 0;
    For(u, 0, n){
        ForEach(v, g[u]){
            if (good[u] || good[v]){
                con++;
            }
        }
    }

    cout << res - con / 2 << endl;

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}