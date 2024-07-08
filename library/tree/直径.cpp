#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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

using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;
int N;
Graph G;

ll rec(int v, int p, ll &ans) {
    vector<ll> chs;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        chs.push_back(rec(e.first, v, ans) + e.second);
    }
    sort(chs.begin(), chs.end(), greater<ll>());
    if (chs.size() == 0) return 0;
    else if (chs.size() == 1) chmax(ans, chs[0]);
    else chmax(ans, chs[0] + chs[1]);
    return chs[0];
}

int main(){

    int n; cin >> n;
    ll sum = 0;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    // 木の直径を求める ans (重みはすべて１とする)
    auto calc_diameter = [&](auto self, int pos, int pre, ll &d) -> ll {
        vector<ll> chs;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            chs.push_back(self(self, (int)nxt, pos, d)+1);
        }
        sort(chs.rbegin(), chs.rend());
        if(chs.size() == 0) return 0;
        else if(chs.size() == 1) chmax(d, chs[0]);
        else chmax(d, chs[0]+chs[1]);
        return chs[0];
    };
    long long ans = 0;
    calc_diameter(calc_diameter, 0, -1, ans);
    cout << sum*2-ans << endl;




    
    return 0;
}