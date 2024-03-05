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

    int n;
    cin >> n;

    vi a(n);
    For(i, 0, n){
        cin >> a[i];
    }
    vi b(n);
    For(i, 0, n){
        cin >> b[i];
    }
    vi c(n);
    For(i, 0, n){
        cin >> c[i];
    }

    vi orda(n);
    For(i, 0, n){
        orda[i] = i;
    }
    sort(All(orda), [&](int i, int j){
        if (a[i] > a[j]){
            return true;
        }else if (a[i] < a[j]){
            return false;
        }else{
            if (b[i] > b[j]){
                return true;
            }else if (b[i] < b[j]){
                return false;
            }else{
                return i < j;
            }
        }
    });

    vi ordb(n);
    For(i, 0, n){
        ordb[i] = i;
    }
    sort(All(ordb), [&](int i, int j){
        if (b[i] > b[j]){
            return true;
        }else if (b[i] < b[j]){
            return false;
        }else{
            if (a[i] > a[j]){
                return true;
            }else if (a[i] < a[j]){
                return false;
            }else{
                return i < j;
            }
        }
    });

    map <int, bool> ban;
    int j = 0;
    int k = 0;
    For(i, 0, n){
        if (c[i]){
            while (ban[ordb[k]]){
                k++;
            }
            ban[ordb[k]] = true;
            cout << ordb[k]+1 << " ";
        }else{
            while (ban[orda[j]]){
                j++;
            }
            ban[orda[j]] = true;
            cout << orda[j]+1 << " ";
        }
    }
    cout << endl;


    return 0;
}