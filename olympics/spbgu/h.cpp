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
#define Min(vec) *min_element(vec.begin(), vec.end())
#define Max(vec) *max_element(vec.begin(), vec.end())

vector<int> preff(string s) {
    int n = s.size();
    vector<int> p(n, 0);

    for (int i = 1; i < n; i++) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0){
            cur = p[cur - 1];
        }
        if (s[i] == s[cur]){
            p[i] = cur + 1;
        }
    }
    return p;
}

int kmp(string s, string p){
    int n = Len(s);
    int m = Len(p);

    s = s+s;

    auto pref = preff(p);
    int i = 0;
    int j = 0;
    while(i < s.size() && i - j < n){
        if (p[j] == s[i]){
            i++;
            j++;
            if (j == m){
                return i-m;
            }
        }else{
            if (j){
                j = pref[j-1];
            }else{
                i++;
            }
        }
    }

    return -1;
}

string send(string s, string p){
    return s + p;
}

string recieve(string s, string p){
    int n = Len(s) - 100;
    int i = kmp(s, p);

    string res;
    For(j, 0, n){
        res += s[(i + j + 100) % (n + 100)];
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(228);

    string p;
    For(i, 0, 100){
        p += (rand() & 1 ? '1' : '0');
    }

    string w, s;
    int n;
    cin >> w >> n >> s;

    if (w == "send"){
        cout << send(s, p) << endl;
    }else{
        cout << recieve(s, p) << endl;
    }

    // string s;
    // cin >> s;

    // int n = Len(s);

    // string q = send(s, p);
    // cout << q << endl;

    // int sh = rand();
    // string r;
    // For(i, 0, n + 100){
    //     r += q[(i + sh) % (n + 100)];
    // }
    // cout << r << endl;

    // cout << recieve(r, p) << endl;

    return 0;
}