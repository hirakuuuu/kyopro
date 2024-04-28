#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 座標圧縮
void comp(vector<ll>&a){
  set<ll>s(a.begin(),a.end());
  map<ll,int>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}


int main(){
    int n, k; cin >> n >> k;
    vector<ll> h(n+1);
    rep(i, 0, n) cin >> h[i];
    map<ll, int> id, height;
    {
        vector<ll> h_ = h;
        comp(h_);
        rep(i, 0, n+1) id[h[i]] = h_[i];
        rep(i, 0, n+1) height[h_[i]] = h[i];
    }
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1, vector<ll>(n+1, INF)));
    rep(i, 0, n+1){
        if(height[i] == h[0]) dp[1][0][i] = h[0];
        else if(k) dp[1][1][i] = height[i];
    }
    rep(i, 1, n){
        rep(j, 0, k+1){
            rep(l, 0, n+1){
                if(j) chmin(dp[i+1][j][l], dp[i][j-1][l]);
                if(height[l] < h[i]) chmin(dp[i+1][j][id[h[i]]], dp[i][j][l]+(h[i]-height[l]));
                else chmin(dp[i+1][j][id[h[i]]], dp[i][j][l]);
            }
        }
    }
    ll ans = INF;
    rep(i, 0, k+1){
        rep(l, 0, n+1){
            chmin(ans, dp[n][i][l]);
        }
    }
    cout << ans << endl;
     

    
    return 0;
}