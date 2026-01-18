# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")

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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    vector<vector<int>> cnt(n, vector<int>(n));
    rep(i, 0, m){
        cin >> u[i] >> v[i]; u[i]--, v[i]--;
        cnt[u[i]][v[i]]++;
        cnt[v[i]][u[i]]++;
    }

    vector<mint> ans(n+1);
    rrep(i, n-1, 0){
        // i をスタートとしたパスを数える
        vector<vector<mint>> dp(1<<(i+1), vector<mint>(i+1));
        dp[1<<i][i] = 1;
        rep(j, 1<<i, 1<<(i+1)){
            if(!((j>>i)&1)) continue;
            rep(k, 0, i+1){
                if(!((j>>k)&1)) continue;
                if(dp[j][k].val() == 0) continue;
                rep(l, 0, i){
                    if(cnt[k][l] == 0) continue;
                    if(!((j>>l)&1)){
                        dp[j+(1<<l)][l] += dp[j][k]*cnt[k][l];
                    }
                }
            }
        }

        rep(j, 1<<i, 1<<(i+1)){
            if(!((j>>i)&1)) continue;
            int l = __popcount(j);
            rep(k, 0, i){
                if(cnt[i][k] == 0) continue;
                if((j>>k)&1){
                    if(j == (1<<k)+(1<<i)){
                        ans[l] += dp[j][k]*(cnt[i][k]-1)/2;
                    }else{
                        ans[l] += dp[j][k]*cnt[i][k]/2;
                    }
                }
            }
        }
    }
    mint sum = 0;
    rep(i, 2, n+1){
        sum += ans[i];
    }
    cout << sum.val() << endl;
    return 0;
}