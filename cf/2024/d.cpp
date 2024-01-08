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

bool merge(vi &nums){
    int n = Len(nums);

    // Print(nums);
    
    if (n == 1){
        return 1;
    }
    
    if (n & 1){
        bool succ1 = 1;
        vi next1;
        next1.push_back(nums[0]);
        for (int i = 1; i < n; i+=2){
            succ1 &= (abs(nums[i] - nums[i+1]) == 1);
            next1.push_back(min(nums[i], nums[i+1]));
        }

        bool succ2 = 1;
        vi next2;
        for (int i = 0; i < n-1; i+=2){
            succ2 &= (abs(nums[i] - nums[i+1]) == 1);
            next2.push_back(min(nums[i], nums[i+1]));
        }
        next2.push_back(nums[n-1]);

        if (succ1 && succ2){
            return merge(next1) || merge(next2);
        }else if (succ1){
            return merge(next1);
        }else if (succ2){
            return merge(next2);
        }else{
            return 0;
        }

    }else{
        bool succ = 1;
        vi next;
        for (int i = 0; i < n; i+=2){
            succ &= (abs(nums[i] - nums[i+1]) == 1);
            next.push_back(min(nums[i], nums[i+1]));
        }

        return (succ ? merge(next) : 0);
    }
}

void solve(){
    int n;
    cin >> n;

    vi nums(n);
    For(i, 0, n){
        cin >> nums[i];
    }

    cout << (merge(nums) ? "YES" : "NO") << endl;

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