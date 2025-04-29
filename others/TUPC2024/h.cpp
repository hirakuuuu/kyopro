#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector g(n, vector(n, vector<int>(2)));
    rep(i, 0, m){
        int t, x, y, d; cin >> t >> x >> y >> d;
        x--, y--;
        if(g[x][y][t] != 0){
            cout << "No" << endl;
            return 0;
        }
        g[x][y][t] = d;
    }

    vector dp(n, vector(n, vector<bool>(7)));
    dp[0][0][0] = 0;
    rep(i, 0, n) rep(j, 0, n){
        rep(k, 0, 7) rep(l, 0, 7){
            int nk = k-3, nl = l-3;
            if((i > 0 && g[i-1][j][0] != 0) && (j > 0 && g[i][j-1][1] != 0)){
                if(dp[i-1][j][])
            }else if((i > 0 && g[i-1][j][0] != 0)){
              
            }else if((j > 0 && g[i][j-1][1] != 0)){
               
            }else{
            
            }
        }

    }

    vector ans(n, vector<ll>(n, INF));
    ll mi = 0;
    rep(i, 0, n) rep(j, 0, n){
        rep(k, 0, 3) rep(l, 0, 2){
            if(dp[i][j][k][l] == INF) continue;
            ans[i][j] = dp[i][j][k][l];
            chmin(mi, ans[i][j]);
        }
        if(ans[i][j] == INF){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    rep(i, 0, n){
        rep(j, 0, n){
            cout << ans[i][j]-mi << ' ';
        }
        cout << endl;
    }



    return 0;
}