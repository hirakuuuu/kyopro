#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc274/tasks/abc274_d

int main(){
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<vector<bool>> dp_x(n+1, vector<bool>(20001));
    dp_x[0][10000] = true;
    dp_x[1][a[1]+10000] = true;
    rep(i, 2, n+1){
        if(i%2 == 1){
            rep(j, -10000, 10001){
                if(dp_x[i-1][j+10000]){
                    dp_x[i][j+10000+a[i]] = true;
                    dp_x[i][j+10000-a[i]] = true;
                }
            }
        }else{
            rep(j, -10000, 10001){
                dp_x[i][j+10000] = dp_x[i-1][j+10000];
            }
        }
    }

    vector<vector<bool>> dp_y(n+1, vector<bool>(20001));
    dp_y[0][10000] = true;
    rep(i, 1, n+1){
        if(i%2 == 0){
            rep(j, -10000, 10001){
                if(dp_y[i-1][j+10000]){
                    dp_y[i][j+10000+a[i]] = true;
                    dp_y[i][j+10000-a[i]] = true;
                }
            }
        }else{
            rep(j, -10000, 10001){
                dp_y[i][j+10000] = dp_y[i-1][j+10000];
            }
        }
    }

    if(dp_x[n][x+10000] and dp_y[n][y+10000]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}