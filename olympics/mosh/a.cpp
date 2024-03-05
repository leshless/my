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

vi month_distr{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

time_t date_to_days(string s){
    int day = stoi(s.substr(0, 2));
    int month = stoi(s.substr(3, 2));
    int year = stoi(s.substr(6, 4));

    int days = 0;

    days += day - 1; // days
    For(i, 0, month - 1){
        days += month_distr[i]; // months
    }
    days += (year - 1900) * 365; // years
    days += (year - 1900) / 4; // leap
    if (((year % 4 == 0) && (month <= 2)) || (year == 2100)){ 
        days--;
    }


    return days;
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    srand(80085);

    string s1, s2;
    while (cin >> s1 >> s2){
        int t1 = date_to_days(s1);
        int t2 = date_to_days(s2);
        cout << t2 - t1 << endl;
    }

    return 0;
}

