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
    int n;
    cin >> n;

    vi cost(n);
    For(i, 0, n){
        cin >> cost[i];
    }

    int x;
    cin >> x;

    vi combo(4);
    For(i, 0, 4){
        cin >> combo[i];
        combo[i]--;
    }

    int k;
    cin >> k;

    map <int, int> nado;
    For(i, 0, k){
        int a;
        cin >> a;
        a--;

        nado[a]++;
    }

    int res = 0;

    while (1){
        int pc = 0;
        for (int a : combo){
            if (nado[a] != 0){
                pc += cost[a];
            }
        }

        if (pc > x){
            res += x;
            for (int a : combo){
                if (nado[a] != 0){
                    nado[a]--;
                }
            }
        }else{
            break;
        }
    }

    for (auto [a, am] : nado){
        res += cost[a] * am;
    }

    cout << res << endl;

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
