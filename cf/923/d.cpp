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

void solve(){
    int n;
    cin >> n;

    vi nums(n);
    For(i, 0, n){
        cin >> nums[i];
    }

    vi st;

    int cur = nums[0];
    st.push_back(0);
    For(i, 0, n-1){
        if (nums[i] != nums[i+1]){
            st.push_back(i+1);            
        }
    }

    // Print(st);

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;

        auto li = distance(st.begin(), upper_bound(st.begin(), st.end(), l));
        auto ri = distance(st.begin(), upper_bound(st.begin(), st.end(), r));
        if (ri == li){
            cout << -1 << " " << -1 << endl;
        }else{
            cout << l+1 << " " << st[li]+1 << endl;
        }

    }

    return;
}


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}