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
    
    map <int, int> freq;
    vi nums;
    For(i, 0, n){
        int x;
        cin >> x;
        
        freq[x]++;
        nums.push_back(x);
    }



    int q;
    cin >> q;
    
    vi res1;
    vi res2;
    For(j, 1, q+1){
        int i, y;
        cin >> i >> y;
        i--;

        int x = nums[i];
        nums[i] = y;

        freq[x]--;
        if (freq[x] == 0){
            freq.erase(x);
        }
        freq[y]++;

        if (freq.size() == 1){
            res1.push_back(j);
        }
        if (freq.size() == 2){
            res2.push_back(j);
        }
    }

    cout << Len(res1) << " ";
    Print(res1);
    cout << Len(res2) << " ";
    Print(res2);


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