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

const ll MOD = 1e9 + 7;

ll find(vi &nums, ll m){
    int n = Len(nums);

    ll free = 0;    
    ll lock = 0;
    ll cur = 0;
    For(i, 0, n){
        int x = nums[i];
        if (cur + x > m){
            lock += x;
            free = max(free, cur);
            cur = 0;
        }else{
            cur += x;
        }
    }
    free = max(free, cur);

    return max(free, lock);
}

void solve(){
    int n;
    cin >> n;

    vi nums(n);
    For(i, 0, n){
        cin >> nums[i];
    }

    ll l = 0;
    ll r = 1e15;
    while (l < r){
        ll m = (l >> 1) + (r >> 1);
        if ((l == m) || (r == m+1)){
            break;
        }

        ll f1 = find(nums, m);
        ll f2 = find(nums, m+1);
        if (f1 < f2){
            r = m+1;
        }else if (f1 > f2){
            l = m;
        }else{
            
        }

        cout << l << " " << r << endl;
    }
    cout << l << endl;
    ll res1 = min(find(nums, l), find(nums, l+1));

    Reverse(nums);

    l = 0;
    r = 1e15;
    while (l < r){
        ll m = (l >> 1) + (r >> 1);
        if ((l == m) || (r == m+1)){
            break;
        }

        if (find(nums, m) <= find(nums, m+1)){
            r = m+1;
        }else{
            l = m;
        }
    }
    cout << l << endl;
    ll res2 = min(find(nums, l), find(nums, l+1));

    For(i, 0, 20){
        cout << find(nums, i) << " ";
    }
    cout << endl << min(res1, res2) << endl;


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