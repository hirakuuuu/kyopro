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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

#define pll pair<ll, ll>
vector<ll> dijk(int s, vector<vector<pll>> &g){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(g.size(), (1LL<<60));
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
    int n; cin >> n;
    vector<string> c(n);
    vector<vector<int>> rb(n, vector<int>(n));
    rep(i, 0, n){
        cin >> c[i];
        rep(j, 0, n){
            if(c[i][j] == 'R') rb[i][j] = 0;
            else rb[i][j] = 1;
        }
    }

    int ans = 0;
    auto id = [&](int i, int j) -> int{
        return i*n+j;
    };
    rep(_, 0, 2){
        vector<vector<pair<ll, ll>>> g(n*n);
        rep(i, 0, n){
            rep(j, 0, n){
                rep(k, 0, 4){
                    int ni = i+(k-1)%2, nj = j+(k-2)%2;
                    if(!inr(0, ni, n) || !inr(0, nj, n)) continue;
                    if(rb[ni][nj] != rb[0][0]) g[id(i, j)].push_back({id(ni, nj), 1});
                    else g[id(i, j)].push_back({id(ni, nj), 0});
                }
            }
        }
        vector<ll> d = dijk(id(0, 0), g);
        ans += d[id(n-1, n-1)];
        vector<vector<int>> rb_(n, vector<int>(n));
        rep(i, 0, n){
            rep(j, 0, n){
                rb_[i][j] = rb[n-i-1][j];
            }
        }
        swap(rb_, rb);
    }
    cout << ans << endl;
    return 0;
}