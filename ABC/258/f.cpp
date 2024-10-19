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
constexpr ll INF = 4e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        ll b, k, sx, sy, gx, gy; cin >> b >> k >> sx >> sy >> gx >> gy;
        vector<ll> x = {sx, sx+(b-sx%b)%b, sx-(b+sx%b)%b, gx, gx+(b-gx%b)%b, gx-(b+gx%b)%b};
        vector<ll> y = {sy, sy+(b-sy%b)%b, sy-(b+sy%b)%b, gy, gy+(b-gy%b)%b, gy-(b+gy%b)%b};
        
        vector<pair<ll, ll>> p;
        for(auto xx: x) for(auto yy: y){
            p.push_back({xx, yy});
        }
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());

        int m = (int)p.size();
        map<pair<ll, ll>, int> id;
        rep(i, 0, m) id[p[i]] = i;

        vector<vector<pair<ll, ll>>> g(m);
        auto calc2 = [&](pair<ll, ll> start, pair<ll, ll> goal) -> ll {
            if(start == goal) return 0LL;
            auto [x1, y1] = start;
            auto [x2, y2] = goal;
            assert(x1 == x2 || y1 == y2);
            ll time = 0;
            rep(_, 0, 2){
                if(x1 == x2){
                    time = abs(y1-y2);
                    if(x1%b != 0){
                        time *= k; // ただの直線移動
                        if((x1%b+b)%b < (b-x1%b)%b){
                            // (x1, y1) -> (x1-(x1)%b, y1) -> (x1-(x1)%b, y2) -> (x2, y2)
                            chmin(time, 
                                (x1%b+b)%b+((x1%b+b)%b)*(k-1)*(y1%b != 0)
                                +abs(y1-y2)
                                +(x1%b+b)%b+((x1%b+b)%b)*(k-1)*(y2%b != 0)
                            );
                        }else{
                            // (x1, y1) -> (x1+(b-x1)%b, y1) -> (x1+(b-x1)%b, y2) -> (x2, y2)
                            chmin(time, 
                                (b-x1%b)%b+((b-x1%b)%b)*(k-1)*(y1%b != 0)
                                +abs(y1-y2)
                                +(b-x1%b)%b+((b-x1%b)%b)*(k-1)*(y2%b != 0)
                            );
                        }
                    }
                }
                swap(x1, y1), swap(x2, y2);
            }
            return time;
        };
        auto calc = [&](pair<ll, ll> start, pair<ll, ll> goal) -> ll {
            if(start == goal) return 0LL;
            auto [x1, y1] = start;
            auto [x2, y2] = goal;
            assert(x1 == x2 || y1 == y2);
            ll time = 0;
            rep(_, 0, 2){
                if(x1 == x2){
                    time = abs(y1-y2);
                    if(x1%b != 0){
                        time *= k; // ただの直線移動
                        if((x1%b+b)%b < (b-x1%b)%b){
                            // (x1, y1) -> (x1-(x1)%b, y1) -> (x1-(x1)%b, y2) -> (x2, y2)
                            chmin(time, 
                                calc2({x1, y1}, {x1-(x1%b+b)%b, y1})
                                +abs(y1-y2)
                                +calc2({x1-(x1%b+b)%b, y2}, {x2, y2})
                            );
                        }else{
                            // (x1, y1) -> (x1+(b-x1)%b, y1) -> (x1+(b-x1)%b, y2) -> (x2, y2)
                            chmin(time, 
                                calc2({x1, y1}, {x1+(b-x1%b)%b, y1})
                                +abs(y1-y2)
                                +calc2({x1+(b-x1%b)%b, y2}, {x2, y2})
                            );
                        }
                    }
                }
                swap(x1, y1), swap(x2, y2);
            }
            return time;
        };

        rep(i, 0, m){
            rep(j, i+1, m){
                if(p[i].first != p[j].first && p[i].second != p[j].second) continue;
                ll time = calc(p[i], p[j]);
                g[i].push_back({j, time});
                g[j].push_back({i, time});
            }
        }

        vector<ll> dist(m, INF);
        auto dijk = [&](int s) -> void {
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
            que.push({0LL, s});
            dist[s] = 0LL;
            while(!que.empty()){
                auto [d, u] = que.top(); que.pop();
                if(dist[u] < d) continue;
                for(auto [v, time]: g[u]){
                    if(dist[v] <= d+time) continue;
                    dist[v] = d+time;
                    que.push({dist[v], v});
                }
            }
        };
        dijk(id[{sx, sy}]);
        cout << dist[id[{gx, gy}]] << endl;
    }
    
    return 0;
}