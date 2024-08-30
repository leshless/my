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

const ll MOD = 1000000007;

struct Tree{
    vll nums;
    vll tval;

    void build(int v, int tl, int tr) {
        if (tl + 1 == tr){
            tval[v] = nums[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm, tr);

        tval[v] = (tval[2*v] * tval[2*v+1]) % MOD;
    }

    void upd(int v, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l) {
            return;
        }

        if (tl + 1 == tr){
            tval[v] += 1;
            return;
        }
        
        int tm = (tl + tr) / 2;

        upd(2*v, tl, tm, l, r);
        upd(2*v+1, tm, tr, l, r);

        tval[v] = (tval[2*v] * tval[2*v+1]) % MOD;
    }

    ll get(int v, int tl, int tr, int l, int r) {
	if (tl >= r || l >= tr) {
		return 1;
	}
	
    if (l <= tl && tr <= r) {
		return tval[v];
	}

	int tm = (tl + tr) / 2;
    return (get(2*v, tl, tm, l, r) * get(2*v+1, tm, tr, l, r)) % MOD;
}

    Tree(vll &a){
        nums = a;
        int n = nums.size();
        tval.resize(4*n);
        build(1, 0, n);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    int n;
    cin >> n;

    vll nums(n);
    For(i, 0, n){
        cin >> nums[i];
    }

    auto tree = Tree(nums);

    int q;
    cin >> q;
    while (q--){
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1){
            cout << tree.get(1, 0, n, l-1, r) << endl;
        }else{
            tree.upd(1, 0, n, l-1, r);
        }
    }

    return 0;
}