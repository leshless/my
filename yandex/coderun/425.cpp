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

#define All(vec) vec.begin(), vec.end()
#define Len(vec) int(vec.size())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Sort(vec) sort(vec.begin(), vec.end())
#define Min(vec) *min_element(vec.begin(), vec.end())
#define Max(vec) *max_element(vec.begin(), vec.end())

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    int n, q; 
    cin >> n >> q;
    
    vector <pair<int, pi>> events;
    For(i, 0, q){
        int l, r, x;
        cin >> l >> r >> x;
        events.push_back({l, {0, x}});
        events.push_back({r, {1, x}});
    }
    Sort(events);

    vector <int> done(n+1, 0);
    vector <ll> dp(n+1, 0);
    dp[0] = 1;

    For(i, 0, Len(events)){
        bool f = events[i].second.first;
        int x = events[i].second.second;

        if (!f){
            ForR(j, n, x-1){
                dp[j] += dp[j-x];
                dp[j] %= MOD;

                if (dp[j] != 0){
                    done[j] = 1;
                }
            }
        }else{
            For(j, x, n+1){
                dp[j] -= dp[j-x];
                dp[j] %= MOD;
            }
        }
    }

    vi res;
    For(i, 1, n+1){
        if (done[i]){
            res.push_back(i);
        }
    }

    cout << Len(res) << endl;
    Print(res);

    return 0;
}