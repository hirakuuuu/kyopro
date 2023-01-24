#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc283/tasks/abc283_e

int h, w;
ll a[2][1005][1005];
ll dp[2][2][1005];
vector<int> dh = {1, 0, -1, 0};
vector<int> dw = {0, 1, 0, -1};

bool pos_check(int i, int j, int h, int w){
    return (0 <= i and i < h and 0 <= j and j < w);
}

bool is_not_isolate(int i, int j, int h, int w, int t1, int t2, int t3){
    // 右方向
    if(pos_check(i, j+1, h, w) and a[t2][i][j+1] == a[t2][i][j]) return true;
    // 左方向
    if(pos_check(i, j-1, h, w) and a[t2][i][j-1] == a[t2][i][j]) return true;
    // 上方向
    if(pos_check(i-1, j, h, w) and a[t1][i-1][j] == a[t2][i][j]) return true;
    // 下方向
    if(pos_check(i+1, j, h, w) and a[t3][i+1][j] == a[t2][i][j]) return true;
    return false;
}

int main(){
    cin >> h >> w;

    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[0][i][j];
            a[1][i][j] = 1-a[0][i][j];
        }
    }
    rep(i, 0, 2){
        rep(j, 0, 2){
            rep(k, 0, h+1){
                dp[i][j][k] = 1e9;
            }
        }
    }
    rep(t1, 0, 2){
        rep(t2, 0, 2){
            bool f = true;
            rep(i, 0, w){
                if(!is_not_isolate(0, i, h, w, 0, t1, t2)) f = false;
            }
            if(f) dp[t1][t2][1] = t1+t2;
        }
    }

    rep(i, 2, h+1){
        rep(t1, 0, 2){
            rep(t2, 0, 2){
                rep(t3, 0, 2){
                    bool f = true;
                    rep(j, 0, w){
                        if(!is_not_isolate(i-1, j, h, w, t1, t2, t3)) f = false;
                    }
                    if(f) chmin(dp[t2][t3][i], dp[t1][t2][i-1]+t3);
                }
            }
        }
    }

    ll ans = 1e9;
    rep(t1, 0, 2){
        rep(t2, 0, 2){
            chmin(ans, dp[t1][t2][h]);
        }
    }

    if(ans != 1e9) cout << ans << endl;
    else cout << -1 << endl;




    
    return 0;
}