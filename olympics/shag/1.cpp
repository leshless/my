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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector <int> time(6);
    for (int i = 0; i < 6; i++){
        cin >> time[i];
    }

    int mt = 0;
    for (int i = 0; i < 5; i++){
        if (i == 2){
            mt = max(mt, time[i]*5);
        }else if (i == 3){
            mt = max(mt, time[i]*2);
        }else{
            mt = max(mt, time[i]);
        }
    }
    

    cout << (12*60) / (mt + 1 + time[5]) << endl;

    return 0;
}