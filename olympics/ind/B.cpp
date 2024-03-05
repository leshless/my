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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    set <int> numset;
    For(i, 0, n){
        int x;
        cin >> x;
        numset.insert(x);
    }

    vi nums;
    ForEach(x, numset){
        nums.push_back(x);
    }
    n = Len(nums);

    vi mxdiv(n-1);
    For(i, 0, n-1){
        int a = nums[i];
        int b = nums[i+1];

        if (b - a == 1){
            mxdiv[i] = 0;
        }

        int l = 1;
        int r = b;
        while (l < r){
            int m = (l >> 1) + (r >> 1);

            if (a/m + 1 < b/m){
                l = m+1;
            }else{
                r = m;
            }
        }

        mxdiv[i] = l-1;
    }

    vi res(k);
    int i = 0;
    For(j, 1, k+1){
        if (j <= nums[0]){
            res[j-1] = 0;
        }else{
            while (mxdiv[i] < j){
                i++;
            }
            if (i == n){
                res[j-1] = nums[n-1] / j + 1;
            }else{
                res[j-1] = nums[i] / j + 1;
            }
        }
    }


    Print(nums);
    Print(mxdiv);
    Print(res);

    return 0;
}