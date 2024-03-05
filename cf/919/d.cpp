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

const int128 MAX = 1e18;

void solve(){
    int n, q;
    cin >> n >> q;

    vpi ops;
    int128 sz = 0;
    For(i, 0, n){
        pi op;
        cin >> op.ft >> op.sd;

        if (sz < MAX){
            if (op.ft == 1){
                sz++;
            }else{
                op.sd++;
                sz *= op.sd;
            }
            ops.push_back(op);
        }
    }

    Reverse(ops);

    vi res(q);
    For(i, 0, q){
        ll k;
        cin >> k;
        k--;

        int128 cur = sz;
        For(j, 0, n){
            if (ops[j].ft == 1){
                if (k == cur-1){
                    res[i] = ops[j].sd;
                    break;
                }else{
                    cur--;
                }
            }else{
                cur /= ops[j].sd;
                k %= cur;
            }

            if (cur < MAX){
                ll curll = cur;
                j++;

                for (; j < n; j++){
                    if (ops[j].ft == 1){
                        if (k == curll-1){
                            res[i] = ops[j].sd;
                            j = n;
                            break;
                        }else{
                            curll--;
                        }
                    }else{
                        curll /= ops[j].sd;
                        k %= curll;
                    }
                }
            }
        }
    }

    Print(res);

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