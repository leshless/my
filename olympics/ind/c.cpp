#pragma GCC optimize("O2")

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

const int N = 3e5 + 1;
map <int, bool> g[N];
bitset <N> ban;
int cc[N];

void dfs(int u, int c){
    ban[u] = 1;
    cc[u] = c;

    for (auto [v, _] : g[u]){
        if (!ban[v]){
            dfs(v, c);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi a(n);
    For(i, 0, n){
        cin >> a[i];
    }
    vi b(n);
    For(i, 0, n){
        cin >> b[i];
    }

    map <int, bool> all;
    For(i, 0, n){
        if (all.count(a[i]) == 0){
            all[a[i]] = 1;
        }
    }

    for (auto [u, _] : all){
        for (int v = 1; v*v <= u; v++){
            if (u % v == 0){
                if (all.count(v)){
                    g[u][v] = 1;
                    g[v][u] = 1;
                }
                if (all.count(u/v)){
                    g[u][u/v] = 1;
                    g[u/v][u] = 1;
                }
            }
        }
    }

    For(i, 0, n){
        int u = a[i];
        int v = b[i];
        if ((u != v) && (all.count(v))){
            g[u][v] = 1;
            g[v][u] = 1;
        }
    }


    int c = 0;
    for (auto [u, _] : all){
        if (!ban[u]){
            dfs(u, c);
            c++;
        }
        // cout << u << " " << cc[u] << endl;

    }

    int q;
    cin >> q;
    while(q--){
        int i, j;
        cin >> i >> j;
        i--; j--;

        if (cc[a[i]] == cc[a[j]]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }


    // for (auto [_, u] : keys){
    //     cout << u << ": ";
    //     for (auto [v, _] : g[u]){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }


    return 0;
}