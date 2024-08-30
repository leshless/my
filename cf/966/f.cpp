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

void solve(){
    int n, k;
    cin >> n >> k;

    vpi rect(n);
    For(i, 0, n){
        cin >> rect[i].ft >> rect[i].sd;
    }

    int res = 0;

    sort(rect.begin(), rect.end(), [](pi r1, pi r2){
        if (r1.ft + r1.ft > r2.ft + r2.ft){
            return true;
        }else if (r1.ft + r1.ft < r2.ft + r2.ft){
            return false;
        }else{
            return (r1.ft * r1.ft < r2.ft * r2.ft);
        }
    });

    For(i, 0, n){
        if (rect[i].ft + rect[i].sd <= k){
            k -= (rect[i].ft + rect[i].sd);
            res += rect[i].ft * rect[i].sd;
            rect[i].ft = -1;
        }
    }

    while (k > 0){
        int s1 = 10000;
        int s2 = 10000;
        int j = -1;

        For (i, 0, n){
            pi r = rect[i];

            if (r.ft == -1){
                continue;
            }

            if (r.ft < s1){
                s1 = r.ft;
                s2 = r.sd;
                j = i;
            }else if (r.ft == s1){
                if (r.sd < s2){
                    s1 = r.ft;
                    s2 = r.sd;
                    j = i;
                }
            }

            if (r.sd < s1){
                s1 = r.sd;
                s2 = r.ft;
                j = i;
            }else if (r.sd == s1){
                if (r.ft < s2){
                    s1 = r.sd;
                    s2 = r.ft;
                    j = i;
                }
            }
        }

        if (j == -1){
            cout << -1 << endl;
            return;
        }
        if (rect[j].ft == 1 && rect[j].sd == 1){
            k -= 2;
            rect[j].ft = -1;
            rect[j].sd = -1;

            res += 1;
        }else{
            k -= 1;
            if (rect[j].ft < rect[j].sd){
                res += rect[j].ft;
                rect[j].sd--;
            }else{
                res += rect[j].sd;
                rect[j].ft--;
            }
        }
    }

    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}//