#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // 直径の端点を求める
    vector<int> dist(n, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q_]+1;
            que.push(nq);
        }
    }
    int L = 0;
    rep(i, 1, n){
        if(dist[L] < dist[i]) L = i;
    }

    fill(dist.begin(), dist.end(), -1);
    que.push(L);
    dist[L] = 0;
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q_]+1;
            que.push(nq);
        }
    }
    int R = 0;
    rep(i, 1, n){
        if(dist[R] < dist[i]) R = i;
    }

    int diam = dist[R];
    vector<vector<int>> d(2, vector<int>(n, -1));
    que.push(L);
    d[0][L] = 0;
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(d[0][nq] != -1) continue;
            d[0][nq] = d[0][q_]+1;
            que.push(nq);
        }
    }
    que.push(R);
    d[1][R] = 0;
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(d[1][nq] != -1) continue;
            d[1][nq] = d[1][q_]+1;
            que.push(nq);
        }
    }

    if(diam%2){
        int c1 = -1, c2 = -1;
        rep(i, 0, n){
            if(d[0][i] == diam/2 && d[1][i] == diam/2+1) c1 = i;
            if(d[1][i] == diam/2 && d[0][i] == diam/2+1) c2 = i;
        }
        auto dfs = [&](auto sfs, int pos, int pre, int depth) -> ll {
            ll res = 0;
            if(depth == diam/2) res++;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                res += sfs(sfs, nxt, pos, depth+1);
            }
            return res;
        };
        ll ans = (dfs(dfs, c1, c2, 0)*dfs(dfs, c2, c1, 0))%MOD;
        cout << ans << endl;
    }else{
        int c = -1;
        rep(i, 0, n){
            if(d[0][i] == diam/2 && d[1][i] == diam/2){
                c = i;
                break;
            }
        }
        auto dfs = [&](auto sfs, int pos, int pre, int depth) -> ll {
            ll res = 0;
            if(depth == diam/2-1) res++;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                res += sfs(sfs, nxt, pos, depth+1);
            }
            return res;
        };
        vector<ll> cnt;
        for(auto cc: g[c]){
            ll tmp = dfs(dfs, cc, c, 0);
            if(tmp > 0) cnt.push_back(tmp);
        }
        vector<ll> dp(cnt.size()+1);
        dp[0] = 1;
        ll sum = 0;
        rep(i, 0, cnt.size()){
            dp[i+1] = dp[i]+dp[i]*cnt[i];
            dp[i+1] %= MOD;
            sum += cnt[i];
            sum %= MOD;
        }
        ll ans = (dp[cnt.size()]-sum-1+MOD)%MOD;
        cout << ans << endl;
    }
    
    return 0;
}