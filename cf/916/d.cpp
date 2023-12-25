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

int step(vi &a, vi &b, vi &c){
    int n = Len(a);

    int sc = 0;
    int sb = 0;
    int sa = 0;
    For(i, 0, n){
        sc = max(sc, sb + c[i]);
        sb = max(sb, sa + b[i]);
        sa = max(sa, a[i]);
    }
    return sc;
}

void solve(){
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

    vi c(n);
    For(i, 0, n){
        cin >> c[i];
    }

    vi res{
        step(a, b, c),
        step(a, c, b),
        step(b, a, c),
        step(b, c, a),
        step(c, a, b),
        step(c, b, a),
    };

    cout << Max(res) << endl;
    
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}