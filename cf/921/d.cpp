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

const ll MOD = 1e9 + 7;

int128 modexp(int128 x, int128 n){
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return modexp((x * x) % MOD, n / 2);
    }
    else {
        return (x * modexp((x * x) % MOD, (n - 1) / 2) % MOD);
    }
}
 
ll getFractionModulo(int128 a, int128 b){
    int128 c = __gcd(a, b);
 
    a = a / c;
    b = b / c;
 
    int128 d = modexp(b, MOD - 2);
 
    ll ans = ((a % MOD) * (d % MOD)) % MOD;
 
    return ans;
}

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;

    int128 tot = n * (n - 1) / 2;
    int128 sum = 0;
    For(i, 0, m){
        int a, b, f;
        cin >> a >> b >> f;
        sum += f;
    }

    int128 res = 0;
    For(i, 0, k){
        res += sum*tot + (m*i);
    }

    
    cout << getFractionModulo(res, tot*tot) << endl;

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