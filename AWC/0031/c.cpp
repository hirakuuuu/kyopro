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
    ll n, d, s, t; cin >> n >> d >> s >> t;
    s--, t--;
    vector<ll> x(n), y(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
    }
    vector<vector<int>> g(n);
    rep(i, 0, n){
        rep(j, 0, n){
            if(i == j) continue;
            if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= d*d) g[i].push_back(j);
        }
    }
    
    queue<int> que;
    que.push(s);
    vector<int> dist(n, -1);
    dist[s] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q]+1;
            que.push(nq);
        }
    }

    cout << dist[t] << endl;
    return 0;
}