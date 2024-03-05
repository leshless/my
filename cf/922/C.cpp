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

void printbin(ll a){
    string res = "";
    while (a > 0){
        res += (a % 2 ? '1' : '0');
        a /= 2;
    }
    Reverse(res);
    cout << res << endl;
}

void solve(){
    ll a, b, r;
    cin >> a >> b >> r;

    ll x = a ^ b;
    
    bool first;
    bool done = 0;
    ll res = 0;
    ForR(i, 64, 0){
        ll cur = (1ll << i);
        if (x & cur){
            if (!done){
                done = 1;
                first = (b & cur) != 0;
            }else{
                if (((b & cur) != 0) == first){
                    if (res + cur <= r){
                        res += cur;
                    }
                }
            }
        }

    }

    cout << abs((a^res) - (b^res)) << endl;

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