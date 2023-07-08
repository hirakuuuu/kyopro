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
// https://atcoder.jp/contests/abc309/tasks/abc309_d



// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<ll> dijk(int s, vector<vector<pll>> &g){
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
    int n1, n2, m; cin >> n1 >> n2 >> m;
    vector<vector<ll>> g1(n1), g2(n1+n2);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        if(b < n1){
            g1[a].push_back(b);
            g1[b].push_back(a);
        }else{
            g2[a].push_back(b);
            g2[b].push_back(a);
        }
    }

    

    vector<ll> d1(n1, -1);
    queue<ll> que;
    que.push(0);
    d1[0] = 0;
    while(!que.empty()){
        ll q = que.front(); que.pop();
        for(auto nq: g1[q]){
            if(d1[nq] != -1) continue;
            que.push(nq);
            d1[nq] = d1[q]+1;
        }
    }
    vector<ll> d2(n1+n2, -1);
    que.push(n1+n2-1);
    d2[n1+n2-1] = 0;
    while(!que.empty()){
        ll q = que.front(); que.pop();
        for(auto nq: g2[q]){
            if(d2[nq] != -1) continue;
            que.push(nq);
            d2[nq] = d2[q]+1;
        }
    }
    int max_d1 = 0, max_d2 = 0;
    rep(i, 0, n1){
        chmax(max_d1, d1[i]);
    }
    rep(i, n1, n1+n2){
        chmax(max_d2, d2[i]);
    }

    cout << max_d1+max_d2+1 << endl;




    
    return 0;
}