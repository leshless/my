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

const int K = 5 * 1e5 + 4;
const int N = 1001;
bitset <K> dp[N];



void solve(){
    dp[0][0] = 1;

    int n;
    cin >> n;

    vi nums(n);
    int sum = 0;
    For(i, 0, n){
        cin >> nums[i];
        sum += nums[i];
    }

    if (sum % 2){
        cout << "NO" << endl;
        return;
    }
    sum /= 2;

    For(i, 1, n+1){
        int x = nums[i-1];
        For(j, 0, sum+1){
            if (j < x){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-x];
            }
        }
    }

    // For(i, 0, 5){
    //     For(j, 0, 10){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    if (!dp[n][sum]){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    vector <bool> sign(n, 0);
    ForR(i, n+1, 1){
        int x = nums[i-1];
        if ((sum >= x) && dp[i-1][sum-x]){
            sum -= x;
            sign[i-1] = 1;
        }
        if (sum == 0){
            break;
        }
    }

    if(sign[0]){
        For(i, 0, n){
            sign[i] = !sign[i];
        }
    }

    cout << nums[0];
    bool part = 0;
    For(i, 1, n){
        if (!part){
            if (sign[i] == part){
                cout << "+" << nums[i];
            }else{
                cout << "=" << nums[i];
                part = 1;
            }
        }else{
            if (sign[i] == part){
                cout << "+" << nums[i];
            }else{
                cout << "-" << nums[i];
            }
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}