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

    string s;
    cin >> s;

    
    int pos = 0;
    int dir = 1;
    For(i, 0, n){
        switch (s[i]){
           case 'F':
            pos += dir;
            break;
        case 'L':
            dir = -1;
            break;
        case 'R':
            dir = 1;
            break;
        }
    }
    int last = pos;

    vector <int> type{1};
    vector <int> steps{0};
    For(i, 0, n){
        switch (s[i]){
        case 'F':
            steps[Len(steps)-1]++;
            break;
        case 'L':
            type.push_back(-1);
            steps.push_back(0);
            break;
        case 'R':
            type.push_back(1);
            steps.push_back(0);
            break;
        }
    }
    int m = Len(type);

    map <int, bool> reach;
    int prevdir = 1;
    
    For(i, 0, m){
        dir = type[i];
        int st = steps[i];

        if (i != 0){
            reach[last - dir * st + prevdir * (st + 1)] = 1; // R/L -> F
            reach[last - 2 * dir * st] = 1; // R/L -> L/R
        }

        if (st != 0){
            reach[last - 1 * dir] = 1; // F -> L/R (same)
        }
        For(j, 0, st){
            reach[last - dir * (st - j) - dir * (st - j - 1)] = 1; // F -> L/R (other)
        }

        // cout << i << " ";
        // Print(reach);

        prevdir = dir;
    }

    cout << Len(reach) << endl;
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