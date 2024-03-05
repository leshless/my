#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

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

bool solve(vi &seg, vi &grandi){
    vi toxor;
    int cur = 0;
    For(i, 0, Len(seg)){
        if (seg[i] != 0){
            cur++;
        }else if (cur != 0){
            toxor.push_back(cur);
            cur = 0;
        }
    }
    if (cur != 0){
        toxor.push_back(cur);
    }

    if ((Len(toxor) == 1) && (toxor[0] == Len(seg))){
        return !(grandi[toxor[0]-2] != 0);
    }

    int x = 0;
    For(i, 0, Len(toxor)){
        x ^= toxor[i];
    }

    return (grandi[x] != 0);
}

const int N = 5000;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vi grandi(n+1);
    bitset <N> mex;
    
    grandi[0] = 0;
    grandi[1] = 1;
    For(p, 2, n+1){
        mex[grandi[p-1]] = 1;
        mex[grandi[p-2]] = 1;

        For(a, 0, p-2){
            mex[grandi[a] ^ grandi[p-2-a]] = 1;
        }

        For(i, 0, n){
            if (!mex[i]){
                grandi[p] = i;
                break;
            }
        }

        mex.reset();
    }

    ld xc, yc;
    cin >> xc >> yc;

    vld polar(n);
    For(i, 0, n){
        ld x, y;
        cin >> x >> y;
        polar[i] = atan2l(y - yc, x - xc);
    }    
    Sort(polar);

    vi seg(n, 0);
    For(i, 0, m){
        ld x, y;
        cin >> x >> y;

        auto it = lower_bound(All(polar), atan2l(y - yc, x - xc));
        if (it == polar.end()){
            seg[0]++;
        }else{
            int j = distance(polar.begin(), it);
            seg[j]++;
        }
    }

    cout << (solve(seg, grandi) ? "Alice" : "Bob") << endl;

    while (q--){
        char t;
        ld x, y;
        cin >> t >> x >> y;

        auto it = lower_bound(All(polar), atan2l(y - yc, x - xc));
        int j;
        if (it == polar.end()){
            j = 0;
        }else{
            j = distance(polar.begin(), it);
        }

        if (t == '+'){
            seg[j]++;
        }else{
            seg[j]--;
        }

        cout << (solve(seg, grandi) ? "Alice" : "Bob") << endl;
    }


    return 0;
}