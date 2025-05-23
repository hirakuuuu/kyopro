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

// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<ll> dijk(int s, vector<vector<pair<ll, ll>>> &g){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    vector<ll> dist(g.size(), (1LL<<60));
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pair<ll, ll> q = que.top(); que.pop();
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
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h){
        cin >> s[i];
    }
    int a, b, c, d; cin >> a >> b >> c >> d; a--, b--, c--, d--;

    auto id = [&](int i, int j) -> int {
        return i*w+j;
    };

    vector<vector<pair<ll, ll>>> g(h*w);
    rep(i, 0, h) rep(j, 0, w){
        rep(k, 0, 4){
            int ni = i+(k-1)%2, nj = j+(k-2)%2;
            if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
            if(s[ni][nj] == '#'){
                g[id(i, j)].emplace_back(id(ni, nj), 1);
                ni += (k-1)%2, nj += (k-2)%2;
                if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                g[id(i, j)].emplace_back(id(ni, nj), 1);
            }else{
                g[id(i, j)].emplace_back(id(ni, nj), 0);
                ni += (k-1)%2, nj += (k-2)%2;
                if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                if(s[ni][nj] == '#'){
                    g[id(i, j)].emplace_back(id(ni, nj), 1);

                }else{
                    g[id(i, j)].emplace_back(id(ni, nj), 0);
                }
            }
        }
    }

    vector<ll> dist = dijk(id(a, b), g);
    cout << dist[id(c, d)] << endl;



    return 0;
}