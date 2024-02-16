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

bool check1(int a){
    a = abs(a);
    return ((a % 10) == ((a / 10) % 10));
}

bool check2(int a, int b){
    a = abs(a);
    b = abs(b);
    return ((a % 10) == ((b / 10) % 10)) || ((b % 10) == ((a / 10) % 10));
}

bool check3(int a, int b){
    a = abs(a);
    b = abs(b);
    return (a % 7 == 0) != (b % 7 == 0);
}

bool check4(int a, int b, int p){
    return (a*a + b*b <= p*p);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    vi nums;
    int x;
    while (cin >> x){
        nums.push_back(x);
    }
    int n = Len(nums);

    int p = INT_MAX;
    For(i, 0, n){
        int a = nums[i];
        if (check1(a)){
            p = min(p, a);
        }
    }

    int c = 0;
    int mx = INT_MIN;
    For(i, 0, n-1){
        int a = nums[i];
        int b = nums[i+1];

        if (check2(a, b) && check3(a, b) && check4(a, b, p)){
            c++;
            mx = max(mx, a*a + b*b);
        }
    }    

    Print(c);
    Println(mx);

    return 0;
}