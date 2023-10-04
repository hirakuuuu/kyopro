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
// https://atcoder.jp/contests/abc142/tasks/abc142_f

vector<vector<int>> g;


// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<ll> dijk(int s){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(1005, (1LL<<60));
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pll q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            ll v = nq, cost = 1;
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
    vector<int> a(m), b(m);
    g.resize(n);
    vector<vector<int>> rev_g(n);
    vector<vector<ll>> dist(n);
    rep(i, 0, m){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        rev_g[b[i]].push_back(a[i]);
    }

    queue<int> que;
    rep(i, 0, n){
        dist[i] = dijk(i);
    }

    int tmp = 1001001001, ind = -1;
    rep(i, 0, m){
        if(dist[b[i]][a[i]] < tmp){
            ind = i;
            tmp = dist[b[i]][a[i]];
        }
    }

    if(ind == -1){
        cout << -1 << endl;
    }else{
        vector<int> ans;
        ans.push_back(a[ind]);
        int pos = a[ind], d = dist[b[ind]][a[ind]];
        while(pos != b[ind]){
            for(auto npos: rev_g[pos]){
                if(dist[b[ind]][npos] == d-1){
                    ans.push_back(npos);
                    pos = npos;
                    d--;
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto aa: ans){
            cout << aa+1 << endl;
        }
    }
    
    return 0;
}