#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;
constexpr ll MOD = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n, q; cin >> n >> q;

    auto d = [&](auto self, int si, int sj, int ti, int tj) -> ll {
        ll res = INF;
        if(si == ti || sj == tj) return res;
        if(si == sj && ti == tj){
            res = 0;
        }else if(si == sj){
            if(!inr(min(ti, tj), si, max(ti, tj))){
                res = max(ti, tj)-min(ti, tj);
            }else{
                res = n-(max(ti, tj)-min(ti, tj));
            }
        }else if(ti == tj){
            if(!inr(min(si, sj), ti, max(si, sj))){
                res = max(si, sj)-min(si, sj);
            }else{
                res = n-(max(si, sj)-min(si, sj));
            }
        }else{
            if(si != tj) chmin(res, self(self, si, si, ti, tj)+self(self, si, sj, tj, tj));
            if(ti != sj) chmin(res, self(self, si, sj, ti, ti)+self(self, sj, sj, ti, tj));
        }
        return res;
    };

    char pre = 'L';
    int pos = 0;
    vector<ll> dp(n, INF); // dp[i] := pre で固定されていない方が i にいるときの最小手数
    dp[1] = 0;
    while(q--){
        char c; cin >> c;
        int t; cin >> t; t--;

        if(c == pre){
            vector<ll> ndp(n, INF);
            // pos -> t, 
            rep(i, 0, n){
                if(t != i) chmin(ndp[i], dp[i]+d(d, pos, t, i, i));
                chmin(ndp[(t+1)%n], dp[i]+d(d, pos, t, i, (t+1)%n));
                chmin(ndp[(t-1+n)%n], dp[i]+d(d, pos, t, i, (t-1+n)%n));
            }
            swap(dp, ndp);
            pos = t;
        }else{
            vector<ll> ndp(n, INF);
            // i -> t, pos 不定
            rep(i, 0, n){
                if(pos != t) chmin(ndp[pos], dp[i]+d(d, pos, pos, i, t));
                chmin(ndp[(t+1)%n], dp[i]+d(d, pos, (t+1)%n, i, t));
                chmin(ndp[(t-1+n)%n], dp[i]+d(d, pos, (t-1+n)%n, i, t));
            }
            swap(dp, ndp);
            pre = c;
            pos = t;
        }

        // assert(dp[t] == INF);

        // rep(i, 0, n){
        //     cout << dp[i] << ' ';
        // }
        // cout << endl;
    }
    ll ans = INF;
    rep(i, 0, n) chmin(ans, dp[i]);
    cout << ans << endl;
    return 0;
}