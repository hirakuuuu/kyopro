#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc201/tasks/abc201_e

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}


int main(){
    int n; cin >> n;
    vector<vector<pll>> g(n+1);
    rep(i, 0, n-1){
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    queue<ll> que;
    que.push(1);
    vector<ll> dist(n+1);
    vector<bool> seen(n+1);
    seen[1] = true;
    while(!que.empty()){
        ll q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(seen[nq.first]) continue;
            seen[nq.first] = true;
            dist[nq.first] = nq.second^dist[q];
            que.push(nq.first);
        }
    }

    vector<ll> cnt(60);
    rep(i, 1, n+1){
        rep(j, 0, 60){
            if((dist[i]&(1LL<<j)) > 0){
                cnt[j]++;
            }
        }
    }

    ll ans = 0;
    rep(i, 1, n+1){
        vector<ll> cnt_ = cnt;
        rep(j, 0, 60){
            if((dist[i]&(1LL<<j)) > 0) cnt_[j] = n-cnt[j];
            ans += cnt_[j]*((1LL<<j)%MOD);
            ans %= MOD;
        }        
    }

    ans *= power(2, MOD-2);
    ans %= MOD;

    cout << ans << endl;




    
    return 0;
}