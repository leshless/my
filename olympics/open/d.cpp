#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
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
template <typename T>
void Print(map <T, T> &vec) {
    for (auto &[k, v] : vec){
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

void timeout(int dur) {
    auto st = high_resolution_clock::now();
    while (true) {
        auto nt = high_resolution_clock::now();
        auto dt = duration_cast<milliseconds>(nt - st).count();
        if (dt >= dur) {
            break;
        }
    }
}

void answer(bool f){
    cout << (f ? "Yes" : "No") << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, s;
    cin >> n >> t >> s;

    vi nums(n);
    For(i, 0, n){
        cin >> nums[i];
    }
    Reverse(nums);

    map <int, int> idx;
    For(i, 0, n){
        idx[nums[i]] = i;
    }

    vi seg(n);
    int cur = 0;
    For(i, 0, n){
        if (nums[i] < t){
            int d = (t - nums[i]) / s + ((t - nums[i]) % s != 0);
            t -= s*d;
            cur += d;
        }
        seg[i] = cur;
    }

    vi pref(n);
    pref[0] = 0;
    cur = 0;
    For(i, 1, n){
        pref[i] = max(pref[i-1] - (seg[i] - seg[i-1]) + 1, 0);
    }

    // cur = 0;
    // For(i, 0, n){
    //     while (seg[i] != cur){
    //         cout << "| ";
    //         cur++;
    //     }
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    // Print(pref);

    int q;
    cin >> q;

    while (q--){
        int x, j;
        cin >> x >> j;
        j--;

        int i = idx[x];

        if (i < j){
            answer(pref[i] >= seg[j] - seg[i]);
        }else if (j < i){
            answer(pref[j] >= seg[i] - seg[j]);
        }else{
            answer(1);
        }
    }
    
    return 0;
}