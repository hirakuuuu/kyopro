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

/*
辺が部分列しか使えない→前から考えれば、その時点で使える辺を使って移動した各頂点への距離がわかる
これを使えば、今の辺を通って移動した場合の更新も簡単にできる

脳死でダイクストラに行ってしまった...
*/

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<ll> a(m), b(m), c(m);
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, 0, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        g[a[i]].push_back({b[i], c[i]});
    }
    vector<int> e(k);
    rep(i, 0, k){
        cin >> e[i]; e[i]--;
    }

    vector<ll> dp(n, INF);
    dp[0] = 0;
    rep(i, 0, k){
        chmin(dp[b[e[i]]], dp[a[e[i]]]+c[e[i]]);
    }
    if(dp[n-1] == INF) cout << -1 << endl;
    else cout << dp[n-1] << endl;


    return 0;
}