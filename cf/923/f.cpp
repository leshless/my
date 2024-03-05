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

const int N = 2e5+10;

vector <map<int, int>> g;
bool used[N];
bool bridge[N];
int enter[N];
int ret[N];
int eu[N];
int ev[N];
int ew[N];
int t;

void dfs_bridge(int u){
    t++;
    enter[u] = t;
    ret[u] = t;
    used[u] = 1;

    for (auto [v, e] : g[u]){
        if (used[v]){
            ret[u] = min(ret[u], enter[v]);
        }else{
            dfs_bridge(v);
            ret[u] = min(ret[u], ret[v]);
            if (ret[v] > enter[u]){
                bridge[e] = 1;
            }
        }
    }
}

bool dfs_res(int u, int t, vi &cycle){
    if (u == t){
        cycle.push_back(u);
        return 1;
    }
    used[u] = 1;

    for (auto [v, e] : g[u]){
        if (!used[v]){
            bool found = dfs_res(v, t, cycle);
            if (found){
                cycle.push_back(u);
                return 1;
            }
        }
    }

    return 0;
}

void solve(){
    int n, m;
    cin >> n >> m;

    g.clear();
    g.resize(n);
    t = 0;

    vi edges(m);
    For(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        edges[i] = i;
        eu[i] = u;
        ev[i] = v;
        ew[i] = w;
        g[u][v] = i;

        bridge[i] = 0;
        used[u] = 0;
        used[v] = 0;
    }


    sort(edges.begin(), edges.end(), [&](int e1, int e2){return ew[e1] < ew[e2];});

    For(u, 0, n){
        if (!used[u]){
            dfs_bridge(0);
        }
    }
    For(u, 0, n){
        used[u] = 0;
    }

    For(e, 0, m){
        if (!bridge[e]){

            vector <int> cycle;
            dfs_res(eu[e], ev[e], cycle);
            cout << ew[e] << "|" << Len(cycle) << endl;
            ForEach(u, cycle){
                cout << u+1 <<  "/";
            }
            cout << endl;
            break;
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