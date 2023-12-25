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
    int m;
    cin >> m;

    vector <int> table(32, 0);

    while (m--){
        int t, v;
        cin >> t >> v;

        if (t == 1){
            table[v]++;

            while (table[v] == 3){
                table[v] = 1;
                table[v+1]++;
                v++;
            }

            // Print(table);
        }else{
            int c = 0;
            bool ign = 0;
            bool f = 1;

            while(v > 0){
                int cur = table[c];
                cur -= (v % 2);
                cur += ign;

                if (cur < 0){
                    f = 0;
                    break;
                }
                if (cur >= 2){
                    ign = 1;
                }else{
                    ign = 0;
                }

                v /= 2;
                c++;
            }

            cout << (f ? "YES" : "NO") << endl;
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