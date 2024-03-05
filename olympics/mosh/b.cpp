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

int n;
int k;
const string alph = "0123456789abcdef";

string gen_token(){
    string res = "";
    For(i, 0, k){
        res += alph[rand() % 16];
    }

    return res;
}


int main(){
    srand(80085);

    cin >> n >> k;

    vector <string> tokens;
    For(i, 0, n){
        while (1){
            string newt = gen_token();

            bool f = 1;
            ForEach(prevt, tokens){
                int c = 0;
                For(j, 0, k){
                    c += (newt[j] == prevt[j]);
                }
                f &= (c < (k-1));
                if (!f){
                    break;
                }
            }

            if (f){
                tokens.push_back(newt);
                break;
            }
        }
    }

    ForEach(t, tokens){
        Println(t);
    }

    return 0;
}