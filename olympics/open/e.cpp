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
#define ForR(i, r, l) for (int i=r-1; i>=l; i--)
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
template <typename T>
void Print(map <T, T> &vec) {
    for (auto &[k, v] : vec){
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

const int N = 1e5 + 10;
const int K = 8;

map <int, int> g[N];
bitset <N> ban;
bool cycle = 0;

int dfs_count(int u){
    ban[u] = 1;

    int res = 1;
    for (auto [v, e] : g[u]){
        if (!ban[v]){
            res += dfs_count(v);
        }else{
            cycle = 1;
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    vi eu(m);
    vi ev(m);
    vi col(m);
    vi cc(k, 0);

    For(e, 0, m){
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--; c--;

        eu[e] = u;
        ev[e] = v;
        col[e] = c;
        cc[c]++;
        g[u][v] = e;
        g[v][u] = e;
    }

    bool con = (dfs_count(0) == n);

    int q;
    cin >> q;

    while (q--){
        int e, c;
        cin >> e >> c;
        e--; c--;

        if (!con){
            cout << "No" << endl;
            continue;
        }

        cc[col[e]]--;
        cc[c]++;
        col[e] = c;

        bool f = 1;
        For(i, 0, k){
            f = f && (cc[i] != 0);
        }

        if (!f){
            cout << "No" << endl;
            continue;
        }

        if (k == 3){
            if (cycle){
                cout << (n > 3 ? "Yes" : "No") << endl;
            }else{
                cout << "Yes" << endl;
            }
        }else{
            cout << "Yes" << endl;
        }
    }

    

    return 0;
}