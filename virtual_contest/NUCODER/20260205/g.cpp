#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

// https://atcoder.jp/contests/abc231/submissions/73013147

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<int> a(n), b(n);
    vector<ll> c(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
        cin >> c[i];
    }

    mcf_graph<ll, ll> g(h+w+2);
    int source = h+w, target = h+w+1;
    g.add_edge(source, target, IINF, 1LL<<40);
    rep(j, 0, h) g.add_edge(source, j, 1, 0);
    rep(i, 0, n){
        g.add_edge(a[i], h+b[i], 1, c[i]);
    }
    rep(j, 0, w) g.add_edge(h+j, target, IINF, 0);
    
    auto [max_flow, min_cost] = g.flow(source, target, h);
    cout << max_flow << endl;
    while(min_cost >= 1LL<<40) min_cost -= 1LL<<40;
    cout << min_cost << endl;
    return 0;
}