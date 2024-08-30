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

    void solve(){
        int n, m;
        cin >> n >> m;

        vi row(m, 0);
        vector <vi> mat(n, row);
        For(i, 0, n){
            string s;
            cin >> s;
            For(j, 0, m){
                mat[i][j] = s[j];
            }
        }

        For(i, 0, n){
            For(j, 0, m){
                int cur = mat[i][j];
                if (cur == '.'){
                    continue;
                }

                int cnt, i1, j1;

                cnt = 0;
                i1 = i;
                j1 = j;
                For(_, 0, 5){
                    if ((i1 < 0) || (i1 >= n) || (j1 < 0) || (j1 >= m)){
                        break;
                    }
                    cnt += mat[i][j] == mat[i1][j1];

                    i1--; j1++;
                }
                if (cnt == 5){
                    cout << "Yes" << endl;
                    return;
                }

                cnt = 0;
                i1 = i;
                j1 = j;
                For(_, 0, 5){
                    if ((i1 < 0) || (i1 >= n) || (j1 < 0) || (j1 >= m)){
                        break;
                    }
                    cnt += mat[i][j] == mat[i1][j1];

                    j1++;
                }
                if (cnt == 5){
                    cout << "Yes" << endl;
                    return;
                }

                cnt = 0;
                i1 = i;
                j1 = j;
                For(_, 0, 5){
                    if ((i1 < 0) || (i1 >= n) || (j1 < 0) || (j1 >= m)){
                        break;
                    }
                    cnt += mat[i][j] == mat[i1][j1];

                    i1++; j1++;
                }
                if (cnt == 5){
                    cout << "Yes" << endl;
                    return;
                }

                cnt = 0;
                i1 = i;
                j1 = j;
                For(_, 0, 5){
                    if ((i1 < 0) || (i1 >= n) || (j1 < 0) || (j1 >= m)){
                        break;
                    }
                    cnt += mat[i][j] == mat[i1][j1];

                    i1++;
                }
                if (cnt == 5){
                    cout << "Yes" << endl;
                    return;
                }
            }
        }

        cout << "No" << endl;


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