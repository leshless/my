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


void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    map <int, bool> a;
    For(i, 0, n){
        int x; 
        cin >> x;
        a[x] = 1;
    }

    map <int, bool> b;
    For(i, 0, m){
        int x; 
        cin >> x;
        b[x] = 1;
    }

    int ac = 0;
    int bc = 0;

    For(cur, 1, k+1){
        if (a.count(cur) && b.count(cur)){
            //
        }else if (a.count(cur)){
            ac++;
        }else if (b.count(cur)){
            bc++;
        }else{
            cout << "NO" << endl;
            return;
        }
    }

    if ((ac <= k/2) && (bc <= k/2)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

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