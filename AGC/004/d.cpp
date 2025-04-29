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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i], a[i]--;
    int ans = 0;
    if(a[0] != 0) ans++, a[0] = 0;

    vector<vector<int>> g(n);
    rep(i, 1, n){
        g[a[i]].push_back(i);
    }
    vector<int> depth(n, -1);
    depth[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(depth[nq] != -1) continue;
            depth[nq] = depth[q]+1;
            que.push(nq);
        }
    }
    
    set<pair<int, int>> s;
    rep(i, 0, n){
        s.insert({depth[i], i});
    }
    vector<int> seen(n);
    while(!s.empty()){
        auto [d, id] = *s.rbegin();
        if(d <= k) break;

        // k-1 個上った先を調べる
        int tmp = id;
        rep(_, 0, k-1) tmp = a[tmp];

        auto f = [&](auto self, int pos, int dep) -> void {
            if(dep == 0) return;
            if(s.find({depth[pos], pos}) == s.end()) return;

            s.erase({depth[pos], pos});
            for(auto nxt: g[pos]){
                self(self, nxt, dep-1);
            }
        };
        f(f, tmp, k);
        ans++;
    }
    cout << ans << endl;

    return 0;
}