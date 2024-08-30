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

void solve(){
    int n, q;
    cin >> n >> q;

    vi p(n+1);
    For(i, 0, n+1){
        p[i] = i;
    }

    vi idx(n+1);
    For(i, 0, n+1){
        idx[i] = i;
    }

    map <int, bool> bad;

    auto check = [&](int u){
        int c1 = u*2;
        int c2 = u*2+1;
        int s = (u % 2 == 1 ? u-1 : u+1);

        if ((idx[u] < idx[c1]) && (idx[u] < idx[c2]) && ((max(idx[c1], idx[c2]) < idx[s]) || (idx[s] < idx[u]))){
            bad.erase(u);
        }else{
            bad[u] = 1;
        }

        return;
    };

    while (q--){
        int i, j;
        cin >> i >> j;

        swap(idx[p[i]], idx[p[j]]);
        swap(p[i], p[j]);

        int u = p[i];
        check(u);
        check(u/2);
        check(u);
        check(u);

    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}