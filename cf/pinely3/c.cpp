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
 
    vpll pairs;
    For(i, 0, n){
        ll x;
        cin >> x;
        pairs.push_back({x, 0});
    }
    For(i, 0, n){
        ll x;
        cin >> x;
        pairs.push_back({x, 1});
    }

    sort(pairs.begin(), pairs.end(), [](pll p1, pll p2){return p1.ft < p2.ft;});

    vll c(n);
    For(i, 0, n){
        cin >> c[i];
    }
    Sort(c);
    Reverse(c);
    
    // for (auto p : pairs){
    //     Print(p.sd);
    // }

    
    vll len;
    int i = 0;
    int j = 2*n-1;
    while(i < j){
        if(pairs[i+1].sd != 0){
            len.push_back(pairs[i+1].ft - pairs[i].ft);
            i+=2;
        }else if(pairs[j-1].sd == 0){
            len.push_back(pairs[j].ft - pairs[j-1].ft);
            j-=2;
        }else{
            len.push_back(pairs[j].ft - pairs[i].ft);
            i++;
            j--;
        }
    }
    Sort(len);
    
    ll res = 0;
    For(i, 0, n){
        res += len[i] * c[i];
    }

    cout << res << endl;
 
    return;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
 
    while(t--){
        solve();
    }
 
    return 0;
}
