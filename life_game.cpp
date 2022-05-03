#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(){
    rep(h, 1, 6) rep(w, 1, 6){
        rep(j, 1, 1<<(h*w)){
            vector<vector<int>> life(h+2, vector<int>(w+2)), ruiseki(h+2, vector<int>(w+2));
            rep(k, 0, h+1){
                rep(l, 0, w+1){
                    if(k < h and l < w) life[k+1][l+1] = (j>>(h*k+l))&1;
                    ruiseki[k+1][l+1] = ruiseki[k][l+1]+ruiseki[k+1][l]-ruiseki[k][l]+life[k+1][l+1];
                }
            }

            bool f1 = true, f2 = false;
            rep(k, 1, h+1){
                rep(l, 1, w+1){
                    int cnt = ruiseki[k+1][l+1]-life[k][l];
                    if(k-2 >= 0 and l-2 >= 0) cnt += ruiseki[k-2][l-2];
                    if(k-2 >= 0) cnt -= ruiseki[k-2][l+1];
                    if(l-2 >= 0) cnt -= ruiseki[k+1][l-2];

                    if(life[k][l]){
                        if(cnt == 2 or cnt == 3) f1 = false;
                        else if(cnt >= 4) f2 = true;
                    }else{
                        if(cnt == 3) f1 = false;
                    }
                }
            }
            if(f1 and f2){
                rep(k, 1, h+1){
                    rep(l, 1, w+1) cout << life[k][l] << " ";
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
    return 0;
}