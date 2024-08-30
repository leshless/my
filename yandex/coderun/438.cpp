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

pair <vector<int>, string> rle(string s){
    pair <vector<int>, string> res;
    
    char cur = s[0];
    int l = 1;
    For(i, 1, Len(s)){
        if (s[i] == cur){
            l += 1;
        }else{
            res.first.push_back(l);
            res.second.push_back(cur);
            cur = s[i];
            l = 1;
        }
    }
    res.first.push_back(l);
    res.second.push_back(cur);

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    auto rle1 = rle(s1);
    auto rle2 = rle(s2);
    auto rle3 = rle(s3);

    // Print(rle1.first);
    // Print(rle1.second);

    if ((Len(rle1.first) != Len(rle2.first)) || (Len(rle2.first) != Len(rle3.first))){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    string res = "";
    For(i, 0, Len(rle1.first)){
        if ((rle1.second[i] != rle2.second[i]) || (rle2.second[i] != rle3.second[i])){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        
        int num = rle1.first[i] + rle2.first[i] + rle3.first[i] - max(max(rle1.first[i], rle2.first[i]), rle3.first[i]) - min(min(rle1.first[i], rle2.first[i]), rle3.first[i]);
        For(j, 0, num){
            res += rle1.second[i];
        }
    }

    Println(res);

    return 0;
}