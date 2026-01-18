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
    int n; cin >> n;
    vector<int> d(n);
    rep(i, 0, n){
        cin >> d[i];
    }

    vector<vector<pair<int, ll>>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        ll w; cin >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<vector<ll>> dp(n);
    rep(i, 0, n){
        dp[i].resize(d[i]+1);
    }
    auto f = [&](auto self, int pos, int pre) -> pair<ll, ll> {
        vector<ll> s1, s2;
        for(auto [nxt, w]: g[pos]){
            if(nxt == pre) continue;
            auto [mx1, mx2] = self(self, nxt, pos);
            if(d[nxt] && mx1+w-mx2 > 0) s1.push_back(mx1+w-mx2);
            s2.push_back(mx2);
        }
        sort(s1.rbegin(), s1.rend());
        sort(s2.rbegin(), s2.rend());

        {
            ll acc = 0;
            rep(i, 0, (int)s2.size()){
                if(s2[i] <= 0) break;
                acc += s2[i];
            }
            dp[pos][0] = acc;
        }
        rep(i, 1, d[pos]+1){
            if((int)s1.size() <= i-1) break;
            dp[pos][i] = dp[pos][i-1]+s1[i-1];
        }
        rep(i, 1, d[pos]+1){
            chmax(dp[pos][i], dp[pos][i-1]);
        }

        ll res = 0;
        rep(i, 0, d[pos]+1) chmax(res, dp[pos][i]);
        if(d[pos] == 0) return {-INF, dp[pos][d[pos]]};
        return {dp[pos][d[pos]-1], dp[pos][d[pos]]};
    };
    f(f, 0, -1);
    ll ans = 0;
    rep(i, 0, d[0]+1) chmax(ans, dp[0][i]);
    cout << ans << endl;


    return 0;
}