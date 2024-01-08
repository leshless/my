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

#define ft first 
#define sd second

#define For(i, l, r) for (int i=l; i<r; i++)
#define ForR(i, l, r) for (int i=r-1; i>=l; i--)
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

const int N = 1e5 + 228;
map <int, int> g[N];
map <int, ll> res;


void dfs(int u, ll am){
    if (g[u].size() == 0){
        res[u] += am;
        return;
    }

    for (auto [v, w] : g[u]){
        dfs(v, am * w);
    }

    return;
}

void solve(){
    int n;
    cin >> n;

    map <string, int> ids;
    map <int, string> names;
    int id = 0;
    
    For(i, 0, n){
        string s;
        int q;
        cin >> s >> q;

        if (ids.count(s) == 0){
            ids[s] = id;
            names[id] = s;
            id++;
        }
        int u = ids[s];

        if (q == 0){
            res[u] = 0;
        }

        while(q--){
            string p;
            int w;
            cin >> p >> w;

            if (ids.count(p) == 0){
                ids[p] = id;
                names[id] = p;
                id++;
            }
            int v = ids[p];

            g[u][v] = w;
        }
    }

    string r;
    cin >> r;
    int t = ids[r];

    dfs(t, 1);

    for (auto [u, am] : res){
        cout << names[u] << " " << am << endl;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}