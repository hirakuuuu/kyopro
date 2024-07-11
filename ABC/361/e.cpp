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

using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;
int N;
Graph G;

long long rec(int v, int p, long long &ans) {
    vector<long long> chs;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        chs.push_back(rec(e.first, v, ans) + e.second);
    }
    sort(chs.begin(), chs.end(), greater<long long>());
    if (chs.size() == 0) return 0;
    else if (chs.size() == 1) chmax(ans, chs[0]);
    else chmax(ans, chs[0] + chs[1]);
    return chs[0];
}

int main(){

    cin >> N;
    ll sum = 0;
    G.assign(N, vector<Edge>());
    for (int i = 0; i < N-1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--, v--;
        sum += w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    long long ans = 0;
    rec(0, -1, ans);
    cout << sum*2-ans << endl;




    
    return 0;
}