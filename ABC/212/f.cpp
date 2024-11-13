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

int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<tuple<ll, ll, ll>>> g(n);
    rep(i, 0, m){
        ll a, b; cin >> a >> b; a--, b--;
        ll s, t; cin >> s >> t;
        g[a].push_back({s, t, b});
    }
    rep(i, 0, n){
        sort(g[i].begin(), g[i].end());
    }

    vector<tuple<ll, ll, ll, ll>> query(q);
    map<ll, vector<pair<ll, ll>>> mp;
    vector<pair<int, int>> ans(q, {-1, -1});
    rep(i, 0, q){
        ll x, y, z; cin >> x >> y >> z; y--;
        tuple<ll, ll, ll> thr = {x, -INF, -INF};
        auto itr = lower_bound(g[y].begin(), g[y].end(), thr);
        if(itr == g[y].end()){
            // cout << i << ' ' << y << endl;
            ans[i] = {y, -1}; // 次に乗るバスがない
        }else{
            auto [s, _, __] = *itr;
            // cout << s << ' ' << z << ' ' << i << endl;
            if(s < z) mp[s].push_back({z, i});
            else ans[i] = {y, -1};
        }
        query[i] = {x, y, z, i};
    }

    sort(query.begin(), query.end());
    rep(i, 0, q){
        auto [x, y, z, j] = query[i];
        if(ans[j].first != -1) continue;
        // cout << i << ' ' << x << endl;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
        auto f = [&](auto self, ll pos, ll tmp) -> void {
            tuple<ll, ll, ll> thr = {tmp, -INF, -INF};
            // for(auto [ss, __, ___]: g[pos]){
            //     cout << ss << ' ';
            // }
            // cout << endl;
            auto itr = lower_bound(g[pos].begin(), g[pos].end(), thr);
            if(itr == g[pos].end()){
                // 次に乗るバスがない
                while(!que.empty()){
                    auto [_, id] = que.top(); que.pop();
                    ans[id] = {pos, -1};
                }
            }else{
                auto [s, t, nxt] = *itr;
                // s に発車するバスに乗るクエリをキューに入れる
                // cout << tmp << ' ' << s << endl;
                while(!mp[s].empty()){
                    // cout << mp[s].back().first << ' ' << mp[s].back().second << endl;
                    que.push(mp[s].back());
                    mp[s].pop_back();
                }
                while(!que.empty() && que.top().first <= s){
                    auto [_, id] = que.top(); que.pop();
                    ans[id] = {pos, -1};
                }
                while(!que.empty() && que.top().first <= t){
                    auto [_, id] = que.top(); que.pop();
                    ans[id] = {pos, nxt};
                }
                if(que.empty()) return;
                self(self, nxt, t);
            }
        };

        f(f, y, x);
    }

    rep(i, 0, q){
        cout << ans[i].first+1;
        if(ans[i].second != -1) cout << ' ' << ans[i].second+1;
        cout << endl;
    }
    
    return 0;
}