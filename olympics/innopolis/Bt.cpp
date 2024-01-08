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


const ll M = 1e9 + 7;

ll gcd(ll a, ll b){
    while (b > 0){
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve(string b, string c){
    ll m = b.size();
    ll k = c.size();

    ll nom;
    ll den;
    if ((m == 0) && (k == 0)){
        cout << -1 << endl;
        return;
    }else if (k == 0){
        nom = stoll(b);
        den = pow(10ll, m);
    }else if (m == 0){
        nom = stoll(c);
        den = 0;
        For(i, 0, k){
            den *= 10;
            den += 9;
        }
    }else{
        nom = stoll(b + c) - stoll(b);
        den = 0;
        For(i, 0, k){
            den *= 10;
            den += 9;
        }
        For(i, 0, m){
            den *= 10;
        }
    }

    cout << nom << "/" << den << " ";
    den /= gcd(nom, den);

    for (ll b = 2; b * b <= den; b++){
        ll p = b;
        while (p <= den){
            if (p == den){
                ll res = b % M;
                Print(den);
                Println(res);
                return;
            }
            p *= b;
        }
    }

    ll res = den % M;
    Print(den);
    Println(res);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    For(f, 0, 100){
        stringstream ss;
        ss << f;
        string b = ss.str();

        b = "0" + b;
        Print(b);
        solve(b, "");
    }


    return 0;
}