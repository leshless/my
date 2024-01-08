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

const int N = 5e4 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (k == 1){
        cout << (n & 1 ? "Marsha" : "Bill") << endl;
        return 0;
    }

    if (n < k){
        cout << "Bill" << endl;
        return 0;
    }
    n -= k;
    
    bitset <N> used;
    vi game(n+1, 0);

    For(i, k, n+1){
        int s = i-k;
        For(j, 0, s/2+1){
            used[game[j] ^ game[s-j]] = 1;
        }

        For(j, 0, n+1){
            if (!used[j]){
                game[i] = j;
                break;
            }
        }

        used.reset();
    }
    

    For(i, 0, n+1){
        cout << i << " " << game[i] << endl;
    }

    cout << (game[n] ? "Bill" : "Marsha") << endl;

    return 0;
}