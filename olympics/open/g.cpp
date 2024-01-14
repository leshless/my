#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

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

bool check(vll &nums, ll a, ll b, ll m){
    int n = Len(nums);
    ll p = m * b;
    ll c = 0;

    if (a > b){
        For(i, 0, n){
            if (nums[i] > p){
                c += (nums[i] - p) / (a - b) + ((nums[i] - p) % (a - b) != 0);
            }
        }   

        return c <= m; 
    }else if (a < b){
        For(i, 0, n){
            if (nums[i] > p){
                return false;
            }
            if (c < m){
                c += (p - nums[i]) / (b - a);
            }
        }

        return c >= m;
    }else{
        For(i, 0, n){
            if (nums[i] > p){
                return false;
            }
        }

        return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll a, b;
    cin >> n >> a >> b;

    // if (a > b){
    //     timeout(100);
    // }else if (a < b){
    //     timeout(200);
    // }else{
    //     timeout(300);
    // }

    vll nums(n);
    For(i, 0, n){
        cin >> nums[i];
        nums[i]++;
    }

    ll l = 0;
    ll r = 1e9 + 10;

    while (l < r){
        ll m = (l >> 1) + (r >> 1);

        if (check(nums, a, b, m)){
            r = m;           
        }else{
            l = m + 1;
        }
    }

    cout << l << endl;


    

    return 0;
}