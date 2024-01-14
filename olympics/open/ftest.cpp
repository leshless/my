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

bitset <500> g[500];
bitset <500> mem[500];
int q = 0;

bool check(int u, int v){
    if (mem[u][v]){
        return 1;
    }
    if (mem[v][u]){
        return 0;
    }

    bool res = g[u][v];
    q++;

    if (res){
        mem[u][v] = 1;
        return 1;
    }else{
        mem[v][u] = 1;
        return 0;
    }

    return 0;
}

void answer(int u){
    cout << "! "  << u+1 << endl;
    return;
}

void solve(){
    For(i, 0, 500){
        mem[i].reset();
    }

    int n = 500;

    bool f = check(0, 1);
    int u1 = !f;
    int v1 = f;
    int u2 = 2;

    For(i, 3, n){
        int v2 = i;
        if (!check(u2, v2)){
            swap(u2, v2);
        }

        if (check(u1, u2)){
            swap(u1, u2);
            swap(u2, v1);
            swap(v1, v2);
        }else{
            swap(v2, u2);
        }
    }

    vi cnd{u1, v1, u2};
    ForEach(u, cnd){
        int c = 0;
        For(v, 0, n){
            if (u != v){
                c += check(u, v);
            }
            if (c == 2){
                break;
            }
        }

        if (c < 2){
            answer(u);
            return;
        }
    }

    answer(-2);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));

    For(u, 0, 500){
        For(v, 0, 500){
            if (u != v){
                bool f = (rand() % 2 != 0);
                g[u][v] = f;
                g[v][u] = !f;
            }
        }
    }

    solve();

    cout << q << endl;

    // int g, t;
    // cin >> g >> t;
    // while(t--){
    //     solve();
    // }

    return 0;
}