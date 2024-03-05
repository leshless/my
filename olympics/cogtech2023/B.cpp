#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
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

void timeout(int dur) {
    auto st = high_resolution_clock::now();
    while (true) {
        auto nt = high_resolution_clock::now();
        auto dt = duration_cast<milliseconds>(nt - st).count();
        if (dt >= dur) {
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    if ((dx > 1) || (dy > 1)){
        cout << 0 << endl;
        return 0;
    }

    int res;
    if (dx){
        if (dy){
            res = 0;
        }else{
            res = 1;
        }   
    }else{
        if (dy){
            res = 1;
        }else{
            res = 3;
        }
    }

    cout << res << endl;

    return 0;
}