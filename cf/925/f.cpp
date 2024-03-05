#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
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
 
#define For(i, l, r) for (int i=l; i<r; ++i)
#define ForR(i, l, r) for (int i=r-1; i>=l; --i)
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

const int N = 2e5+10;

void solve(){
    int n, k;
    cin >> n >> k;

    vi row(n);
    vector <vi> table(k, row);
    For(i, 0, k){
        For(j, 0, n){
            cin >> table[i][j];
        }
    }

    if (k == 1){
        cout << "YES" << endl;
        return;
    }

    if (k == 2){
        int p0 = 1;
        int p1 = 1;
        For(i, 0, n-1){
            if (table[0][p0] != table[1][p1]){
                if ((table[0][0] != table[1][p1]) && (table[1][0] != table[0][p0])){
                    cout << "NO" << endl;
                    return;
                }
                if ((table[0][0] != table[1][p1])){
                    p0++;
                }
                if ((table[1][0] != table[0][p0])){
                    p1++;
                }
            }else{
                p0++;
                p1++;
            }
        }

        cout << "YES" << endl;
        return;
    }


    vi pts(k, 1);
    For(i, 0, n-1){
        map <int, int> freq;
        For(j, 0, k){
            freq[table[j][pts[j]]]++;
        }

        if (freq.size() > 2){
            cout << "NO" << endl;
            return;
        }
        if (freq.size() == 1){
            For(j, 0, k){
                pts[j]++;
            }
            continue;
        }

        int a = freq.begin()->first;
        int b = next(freq.begin(), 1)->first;
        if (freq[a] == 1){
            //
        }else if (freq[b] == 1){
            swap(a, b);
        }else{
            cout << "NO" << endl;
            return;
        }

        For(j, 0, k){
            if (table[j][pts[j]] == b){
                pts[j]++;
            }else if ((table[j][pts[j]] == a) && (table[j][0] == b)){
                //
            }else{
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

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