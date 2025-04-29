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
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> deg(n);
    rep(i, 0, n) deg[i] = (int)g[i].size();

    vector<vector<int>> ng(n);
    rep(i, 0, n){
        if(deg[i] < 4) continue;
        for(auto j: g[i]){
            if(deg[j] < 4) continue;
            ng[i].push_back(j); 
        }
    }

    vector<pair<int, int>> cnt(n, {-1, -1});
    auto f = [&](auto self, int pos, int pre) -> void {
        vector<int> mx;
        for(auto nxt: ng[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            mx.push_back(cnt[nxt].second);
        }
        sort(mx.rbegin(), mx.rend());

        cnt[pos].first = 1+(4-min((int)mx.size(), 4));
        rep(i, 0, min((int)mx.size(), 4)){
            cnt[pos].first += mx[i];
        }

        cnt[pos].second = 1+(3-min((int)mx.size(), 3));
        rep(i, 0, min((int)mx.size(), 3)){
            cnt[pos].second += mx[i];
        }
    };

    rep(i, 0, n){
        if(deg[i] < 4) continue;
        if(cnt[i] != make_pair(-1, -1)) continue;
        f(f, i, -1);
    }
    int ans = -1;
    rep(i, 0, n) chmax(ans, cnt[i].first);
    cout << ans << endl;
    return 0;
}
