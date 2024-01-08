#pragma GCC optimize("O3")
 
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

const int N = 3e5 + 100;

ll merge_step(vi &nums, int l, int r){
    if (r - l <= 1){
        return 0;
    }

    int m = (l + r) / 2;
    ll res = merge_step(nums, l, m) + merge_step(nums, m, r);

    vi p1;
    For(i, l, m){
        p1.push_back(nums[i]);
    }
    vi p2;
    For(i, m, r){
        p2.push_back(nums[i]);
    }

    int i = 0;
    int j = 0;

    while ((i < Len(p1)) && (j < Len(p2))){
        if (p1[i] < p2[j]){
            nums[l+i+j] = p1[i];
            i++;
        }else{
            nums[l+i+j] = p2[j];
            j++;
            res += Len(p1) - i;
        }
    }
    while (i < Len(p1)){
        nums[l+i+j] = p1[i];
        i++;
    }
    while (j < Len(p2)){
        nums[l+i+j] = p2[j];
        j++;
    }

    return res;
}

ll merge_count(vi nums){
    return merge_step(nums, 0, Len(nums));
}

ll min_dif(vi nums){
    int n = Len(nums);
    
    ll cur = 0;
    ll res = 0;
    ForR(i, n, 0){
        cur += n - 2 * nums[i] + 1;
        res = min(res, cur);
    }

    return res;
}

vi restore_first(vi nums, int n){
    bitset <N> markup;

    ForEach(x, nums){
        markup[x] = 1;
    }

    vi res;
    For(x, 1, n+1){
        if (!markup[x]){
            res.push_back(x);
        }
    }

    return res;
}

vi conc(vi &p1, vi &p2){
    vi res;
    res.insert(res.end(), All(p1));
    res.insert(res.end(), All(p2));
    
    return res;
}

string encode(ll a, ll b){
    return to_string(a) + " " + to_string(b);
}

pll decode(string s){
    ll a = stoll(s.substr(0, s.find(" ")));
    ll b = stoll(s.substr(s.find(" ") + 1));
    return {a, b};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(80085);

    string w;
    int n, m;
    cin >> w >> n >> m;

    vi nums(m);
    For(i, 0, m){
        cin >> nums[i];
    }

    if (w == "first"){
        ll inv1 = merge_count(nums);
        ll dif1 = min_dif(nums);

        string s = encode(inv1, dif1);
        
        Println(s);
    }else{
        string s;
        cin >> s;

        pll p = decode(s);
        ll inv1 = p.ft;
        ll dif1 = p.sd;

        ll inv2 = merge_count(nums);
        ll dif2 = min_dif(nums);

        Sort(nums);

        vi p1 = nums;
        vi p2 = restore_first(nums, n);

        ll inv12 = merge_count(conc(p1, p2));
        ll inv21 = merge_count(conc(p2, p1));

        ll res = inv1 + inv2 + min(inv12 + dif2, inv21 + dif1);
        
        cout << res << endl;
    }


    return 0;
}