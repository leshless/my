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
#define ForR(i, r, l) for (int i=r; i>l; i--)
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
template <typename K, typename V>
void Print(map <K, V> &m) {
    for (auto &[k, v] : m){
        cout << k << ":" << v << " ";
    }
    cout << "\n";
}

#define All(vec) vec.begin(), vec.end()
#define Len(vec) int(vec.size())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Sort(vec) sort(vec.begin(), vec.end())
#define Min(vec) *min_element(vec.begin(), vec.end())
#define Max(vec) *max_element(vec.begin(), vec.end())

ll intersection(pll b, pll r){
    return max(0ll, min(b.sd, r.sd) - max(b.ft, r.ft));
}

ll count(vpll &blue, vpll &red, int k){
    ll res = 0;

    int i = 0; 
    int j = 0;

    while((i != Len(blue) && (j != Len(red)))){
        pll b = blue[i];
        pll r = red[j];
        r.ft += k;
        r.sd += k;

        res += intersection(b, r);
        if (r.sd > b.sd){
            i++;
        }else{
            j++;
        }
    }

    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;

    int lb, rb;
    cin >> lb >> rb;

    vpll blue(n);
    For(i, 0, n){
        cin >> blue[i].ft >> blue[i].sd;
    }
    sort(blue.begin(), blue.end(), [&](pll a, pll b){return a.ft < b.ft;});

    vpll red(m);
    For(i, 0, m){
        cin >> red[i].ft >> red[i].sd;
    }
    sort(red.begin(), red.end(), [&](pll a, pll b){return a.ft < b.ft;});

    ll res = LLONG_MAX;

    For(i, 0, n){
        For(j, 0, m){
            pll b = blue[i];
            pll r = red[j];

            // b -> r
            ll k = b.sd - r.ft;
            if ((red[0].ft + k >= lb) && (red[m-1].sd + k <= rb)){
                res = min(res, count(blue, red, k));
            }

            // r -> b
            k = b.ft - r.sd;
            if ((red[0].ft + k >= lb) && (red[m-1].sd + k <= rb)){
                res = min(res, count(blue, red, k));
            }

        }
    }

    // lb
    ll k = lb - red[0].ft;
    res = min(res, count(blue, red, k));

    // rb
    k = rb - red[m-1].sd;
    res = min(res, count(blue, red, k));

    Println(res);


    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}