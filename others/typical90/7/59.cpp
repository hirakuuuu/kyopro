#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

/*
まず、制約をちゃんと見ましょう
DAGなので、トポロジカルソートが可能
その順でDPとかが浮かんでくる
頂点への到達可能性をビットで保持することができそう
→ビットセットで高速化

そのままやるとメモリがきついので、クエリを６４個ごとに分けてあげるとうまくいく
*/

int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }

    vector<int> a(q), b(q);
    rep(i, 0, q){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    rep(i, 0, (64-q%64)%64){
        a.push_back(-1);
        b.push_back(-1);
    }
    int nq = a.size();
    vector<bool> ans(nq);
    for(int i = 0; i < nq; i += 64){
        vector<unsigned long> dp(n);
        rep(j, 0, 64){
            if(a[i+j] == -1) continue;
            dp[a[i+j]] |= (1LL<<j);
        }
        rep(j, 0, n){
            for(auto nxt: g[j]){
                dp[nxt] |= dp[j];
            }
        }
        rep(j, 0, 64){
            if(a[i+j] == -1) continue;
            if(dp[b[i+j]]&(1LL<<j)) ans[i+j] = true;
        }
    }

    rep(i, 0, q){
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    
    return 0;
}