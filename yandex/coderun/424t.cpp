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

void shift(vi& nums){
    int n = Len(nums);
    bool c = 0;

    ForR(i, n-1, -1){
        nums[i] += c;
        c = (nums[i] >= 10);
        nums[i] %= 10;
    }
}

int diff(vi& nums){
    int n = Len(nums);

    int sl = 0;
    For(i, 0, n/2){
        sl += nums[i];
    }

    int sr = 0;
    For(i, n/2, n){
        sr += nums[i];
    }
    
    return sl - sr;
}

void solve_less(vi& nums){
    int d = diff(nums);
    int n = Len(nums);

    ForR(i, n-1, -1){
        int cur = 9 - nums[i];
        if (d > cur){
            nums[i] = 9;
            d -= cur;
        }else{
            nums[i] += d;
            d = 0;
        }
    }
}

void solve_greater(vi& nums){
    int d = diff(nums);
    int n = Len(nums);

    ForR(i, n-1, n/2-2){
        if ((i == n/2-1) || (d >= 0)){
            shift(nums);
            break;
        }

        d += nums[i] - 1;
        nums[i-1]++;
        nums[i] = 0;
    }

    d = diff(nums);

    if (d > 0){
        solve_less(nums);
    }

}

void solve_zero(vi& nums){
    int n = Len(nums);

    For(i, 0, n){
        nums[i] = 0;
    }
    nums[n/2-1] = 1;
    nums[n-1] = 1;
}

vi solve(string s){
    int n = Len(s);

    vi nums;
    For(i, 0, n){
        int x = s[i] - '0';
        nums.push_back(x);
    }
    

    int d = diff(nums);

    if (d == 0){
        nums[n-1] += 1;
        shift(nums);
        d = diff(nums);
    }

    if (d > 0){
        solve_less(nums);
    }else if (d < 0){
        solve_greater(nums);    
    }else{
        solve_zero(nums);
    }

    // cout << "SOL:  ";
    // For(i, 0, n){
    //     cout << nums[i];
    // }
    // cout << endl;

    return nums;
}

vi lazy(string s){
    int n = Len(s);

    vi nums;
    For(i, 0, n){
        int x = s[i] - '0';
        nums.push_back(x);
    }

    while (1){
        nums[n-1] += 1;
        shift(nums);
        int d = diff(nums);

        if ((d == 0) && (Max(nums) != 0)){
            break;
        }
    }

    // cout << "LAZY: ";
    // For(i, 0, n){
    //     cout << nums[i];
    // }
    // cout << endl;

    return nums;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80084);

    int k = 100000;
    int bad = 0;
    For(i, 0, k){
        int n = ((rand() % 4) + 1) * 2;
        string s;
        For(i, 0, n){
            s += '0' + (rand() % 10);
        }

        // cout << "CASE: " << s << endl;
        // lazy(s);
        // solve(s);
        // cout << endl;

        if (lazy(s) != solve(s)){
            cout << s << endl;
            bad++;
        }
    }

    cout << k-bad << "/" << k << endl;


    return 0;
}