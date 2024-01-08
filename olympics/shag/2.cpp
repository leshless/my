#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

bool isU(char x){
    return (x >= 'A') && (x <= 'Z');
}

bool isL(char x){
    return (x >= 'a') && (x <= 'z');
}

char toU(char x){
    return x + ('A' - 'a');
}

char toF(char x){
    if (x == '.'){
        return ',';
    }
    if (x == ','){
        return '.';
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string r;
    while (cin >> r){
        s += " ";
        s += r;
    }

    bool f = 0;
    string res = "";
    for (char x : s){
        if (f){
            if (isL(x)){
                res += toU(x);
                f = 0;
            }else if (isU(x)){
                res += x;
            }else{
                res += toF(x);
                f = 0;
            }
        }else{
            if (x == ' '){
                f = 1;
            }else{
                res += toF(x);
            }
        }
    }

    cout << res << endl;

    

    return 0;
}