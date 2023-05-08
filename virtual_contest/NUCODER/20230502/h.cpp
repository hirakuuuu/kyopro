#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w; cin >> h >> w;
    int a[h+1][w+1], b[h+1][w+1], c[h+1][w+1];
    rep(i, 1, h+1){
        rep(j, 1, w+1) cin >> a[i][j];
    }
    rep(i, 1, h+1){
        rep(j, 1, w+1) cin >> b[i][j];
    }
    rep(i, 1, h+1){
        rep(j, 1, w+1) c[i][j] = abs(a[i][j]-b[i][j]);
    }

    vector<vector<vector<int>>> dp(h+1, vector<vector<int>>(w+1, vector<int>(13001, 0)));
    dp[0][1][0] = dp[1][0][0] = 1;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            rep(k, 0, 13001){
                dp[i][j][k] |= dp[i-1][j][abs(k-c[i][j])];
                dp[i][j][k] |= dp[i][j-1][abs(k-c[i][j])];
                if(k+c[i][j] <= 13000){
                    dp[i][j][k] |= (dp[i-1][j][abs(k+c[i][j])]);
                    dp[i][j][k] |= (dp[i][j-1][abs(k+c[i][j])]);
                } 
            }
        }
    }


    rep(i, 0, 13001){
        if(dp[h][w][i]){
            cout << i << endl;
            return 0;
        }
    }

    
    return 0;
}