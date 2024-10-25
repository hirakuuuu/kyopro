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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> rev;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        if(b == 0) rev.push_back(a);
    }

    queue<int> que;
    que.push(0);
    vector<int> dist(n, IINF);
    dist[0] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != IINF) continue;
            dist[nq] = dist[q]+1;
            que.push(nq);
        }
    }


    int mi = IINF, goal = -1;
    for(auto t: rev){
        if(dist[t] == IINF) continue;
        if(mi > dist[t]){
            mi = dist[t];
            goal = t;
        }
    }
    if(goal == -1) cout << -1 << endl;
    else cout << mi+1 << endl;
    
    return 0;
}