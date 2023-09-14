#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define dbl double
#define ldbl long double
#define uint unsigned int
#define peque priority_queue
#define map unordered_map

struct Node{
    int x;
    int pd;
    Node* l;
    Node* r;

    Node(int xn, int pdn){
        x = xn;
        pd = pdn;
        l = NULL;
        r = NULL;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    Node* wr = NULL;
    Node* br = NULL;
    int wm;
    int bm;
    int res = 0;

    char t;
    int x;
    for (int i = 0; i < n * 2; i++){
        cin >> t >> x;

        if (t == 'W'){
            if (wr == NULL){
                wr = new Node(x, i);
                wm = x;
                continue;
            }

            Node* cur = wr;
            int d = 0;
            while(1){
                if (x < cur->x){
                    d += cur->pd;
                    if (cur->pd >= 0){
                        cur->pd += 1;
                    }
                    if (cur->l == NULL){
                        cur->l = new Node(x, -1);
                        break;
                    }else{
                        cur = cur->l;
                    }
                }else{
                    d += cur->pd;
                    if (cur->pd < 0){
                        cur->pd -= 1;
                    }
                    if (cur->r == NULL){
                        cur->r = new Node(x, 1);
                        d += 1;
                        break;
                    }else{
                        cur = cur->r;
                    }
                }

                res += i - d;
            }
        }else{
            if (br == NULL){
                br = new Node(x, i);
                bm = x;
                continue;
            }

        }
    }

    return 0;
}