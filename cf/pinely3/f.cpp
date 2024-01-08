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

void solve(){
    int n;
    cin >> n;

    vi deg(n, 0);
    vi par(n, -1);
    For(i, 1, n){
        cin >> par[i];
        par[i]--;
        deg[par[i]]++;
    }

    // Print(par);
    // Print(deg);

    stack <int> ord;
    For(i, 0, n){
        if (!deg[i]){
            ord.push(i);
        }
    }

    int res = 0;
    while(!ord.empty()){
        int u = ord.top();
        ord.pop();

        if (ord.empty()){
            int c = 0;
            while (u != -1){
                u = par[u];
                c++;
            }
            res += max(c / 2 - 1, 0);
        }else{
            int v = ord.top();
            ord.pop();

            deg[par[u]]--;
            deg[par[v]]--;
            if (!deg[par[u]]){
                ord.push(par[u]);
            }
            if (par[v] != par[u]){
                if (!deg[par[v]]){
                    ord.push(par[v]);
                }
            }

            res++;
        }
    }

    cout << res << endl;


    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}