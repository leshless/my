#pragma GCC optimize("O3")

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

const int128 N = 2e5 + 1;
const int128 M = 1e9 + 7;

int128 fact[N];

int128 binpow(int128 n, int128 p){
    if (p == 0){
        return 1;
    }
    if (p % 2 == 1){
        return (n * binpow(n, p-1)) % M;
    }else{
        int128 res = binpow(n, p/2);
        return (res * res) % M;
    }
}

int128 c(int128 n, int128 k){
    if(n < k) return 0;
	return (fact[n] * binpow((fact[n - k] * fact[k]) % M, M - 2)) % M;
}

void solve(){
    int n, k;
    cin >> n >> k;

    int x = 0;
    For(i, 0, n){
        bool b;
        cin >> b;
        x += b;
    }

    int128 res = 0;
    For(i, (k+1)/2, k+1){
        if (i > x){
            break;
        }

        int128 cx = c(x, i);
        int128 cy = c(n-x, k-i);
        res += (cx * cy) % M;
    }

    cout << ll(res) << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    fact[0] = 1;
    For(i, 1, N){
        fact[i] = (fact[i-1] * i) % M;
    }

    int t = 1;
    cin >> t;
    while(t--){


        solve();
    }

    return 0;
}//