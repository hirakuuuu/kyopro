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

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<int> x(2), y(2);
    rep(i, 0, 2){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }

    vector<string> c(h);
    rep(i, 0, h) cin >> c[i];
    vector<vector<pair<ll, ll>>> g(((h*w)<<2));
    auto id = [&](int x, int y, int d) -> int {
        assert(inr(0, x, h));
        assert(inr(0, y, w));
        assert(inr(0, d, 4));
        return ((x*w+y)<<2)+d;
    };
    rep(i, 0, h){
        rep(j, 0, w){
            if(c[i][j] == '@') continue;
            rep(l, 0, 4){
                rep(d, 0, 4){
                    if(d != l) g[id(i, j, l)].push_back({id(i, j, d), 1});
                }
                int ni = i+(l-1)%2, nj = j+(l-2)%2;
                if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                if(c[ni][nj] == '@') continue;
                else g[id(i, j, l)].push_back({id(ni, nj, l), 1});

            }
        }
    }

    vector<pair<ll, ll>> dist((h*w)<<2, {INF, INF});
    rep(d, 0, 4){
        dist[id(x[0], y[0], d)] = {1, 0};
    }
    auto dijk = [&](vector<vector<pair<ll, ll>>> g) -> void {
        priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, greater<pair<pair<ll, ll>, ll>>> que;
        rep(d, 0, 4) que.push({dist[id(x[0], y[0], d)], id(x[0], y[0], d)});
        while(!que.empty()){
            auto [q, u] = que.top(); que.pop();
            if(dist[u] < q) continue;
            auto [d, cnt] = q;
            for(auto [v, cost]: g[u]){
                if((u&3) == (v&3) && cnt < k){
                    if(dist[v] > make_pair(d, cnt+cost)){
                        dist[v] = make_pair(d, cnt+cost);
                        que.push({dist[v], v});
                    }
                }else if((u&3) == (v&3)){
                    if(dist[v] > make_pair(d+cost, 1LL)){
                        dist[v] = make_pair(d+cost, 1LL);
                        que.push({dist[v], v});
                    }
                }else{
                    if(dist[v] > make_pair(d+cost, 0LL)){
                        dist[v] = make_pair(d+cost, 0LL);
                        que.push({dist[v], v});
                    }
                }
            }
        }
    };
    dijk(g);
    // rep(i, 0, h){
    //     rep(j, 0, w){
    //         cout << dist[id(i, j, 3)].first << ' ' << dist[id(i, j, 3)].second << endl;
    //     }
    // }

    ll ans = INF;
    rep(i, 0, 4){
        chmin(ans, dist[id(x[1], y[1], i)].first);
    }


    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;


    
    return 0;
}