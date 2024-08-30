#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
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

const int N = 1e8;
const int X = 30;



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

    int128 res = 0;
    int s = 0;
    
    For(_, 0, K){
        int128 mask = 0;
        For(i, 0, 2){
            int128 part = rand();
            mask += part << (i*32);
        }

        For(last, 0, (1 << 31)){
            
            mask += int128(last) << (2*32);

            int sa = 0;
            int sb = 0;
            For(i, 0, n){
                if (mask & (int128(1) << i)){
                    sa += a[i];
                    sb += b[i];
                }
            }

            if ((sa == sb) && (s < sa)){
                res = mask;
                s = sa;
            }
        }
    }

    int c = 0;
    vector <int> ans;
    For(i, 0, n){
        if (res & (int128(1) << i)){
            c++;
            ans.push_back(i+1);
        }
    } 

    cout << c << endl;
    Print(ans);
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    srand(80085);

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}

