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

// 問題
// https://atcoder.jp/contests/abc216/tasks/abc216_g

vector<vector<pll>> g(200005);

// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<ll> dijk(int s){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(200005, (1LL<<60));
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pll q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            ll v = nq.first, cost = nq.second;
            if(dist[v] > d+cost){
                dist[v] = d+cost;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> l(m), r(m), x(m);
    rep(i, 0, n){
        g[i].push_back({i+1, 1});
        g[i+1].push_back({i, 0});

    }
    rep(i, 0, m){
        cin >> l[i] >> r[i] >> x[i];
        g[l[i]-1].push_back({r[i], r[i]-l[i]+1-x[i]});
    }

    vector<ll> ans = dijk(0);
    rep(i, 1, n+1){
        if(ans[i-1] == ans[i]) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    cout << endl;


    
    return 0;
}