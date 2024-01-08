#pragma GCC optimize("O3")
 
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

int check(int i){
    cout << i+1 << endl;
    cout.flush();

    int x;
    cin >> x;

    // vi nums{6, 9, 8, 5, 3, 1, 2};

    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vi find(k);
    For(i, 0, k){
        cin >> find[i];
    }

    int x0 = check(0);
    int xn = check(n - 1);

    bool f = (x0 < xn); // <=> (p < q)

    // finds p if f
    // finds q if !f
    // ~ 2logn
    int l = 0;
    int r = n-2;
    while (l < r){
        int m = (l >> 1) + (r >> 1);
        int x = check(m);
        int y = check(m+1);

        if (f){
            if ((x < y) || (x0 < x)){
                r = m;
            }else{
                l = m + 1;
            }
        }else{
            if ((x > y) || (x0 > x)){
                r = m;
            }else{
                l = m + 1;
            }
        }
    }
    int piv1 = l;

    // finds p if !f
    // finds q if f
    // ~ 2logn
    l = 0;
    r = n-2;
    while (l < r){
        int m = (l >> 1) + (r >> 1);
        int x = check(n - m - 1);
        int y = check(n - m - 2);

        if (!f){
            if ((x < y) || (xn < x)){
                r = m;
            }else{
                l = m + 1;
            }
        }else{
            if ((x > y) || (xn > x)){
                r = m;
            }else{
                l = m + 1;
            }
        }
    }
    int piv2 = n - l - 1;


    int p = (f ? piv1 : piv2);
    int q = (f ? piv2 : piv1);
    
    ForEach(x, find){
        // [p, q]^
        l = p;
        r = (f ? q : n+q);
        while (l < r){
            int m = (l >> 1) + (r >> 1);
            int y = check(m % n);

            if (y > x){
                r = m;
            }else if (y < x){  
                l = m + 1;
            }else{
                // m %= n;
                // Print(m);
                break;
            }
        }

        // [q, p]v
        l = q;
        r = (f ? n+p : p);
        while (l < r){
            int m = (l >> 1) + (r >> 1);
            int y = check(m % n);

            if (y > x){
                l = m + 1;
            }else if (y < x){  
                r = m;
            }else{
                // m %= n;
                // Print(m);
                break;
            }
        }

    }

    cout << 0 << endl;

    return 0;
}