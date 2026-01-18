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
    vector<vector<int>> g(n+m);
    vector<int> wzero;
    rep(i, 0, n){
        int a; cin >> a;
        int f_0 = 0;
        rep(j, 0, a){
            int t; cin >> t; t--;
            g[i+m].push_back(t);
            g[t].push_back(i+m);
            if(t == 0) f_0++;
        }
        if(f_0){
            for(auto t: g[i+m]){
                wzero.push_back(t);
            }
        }
    }
    sort(wzero.begin(), wzero.end());
    wzero.erase(unique(wzero.begin(), wzero.end()), wzero.end());

    vector<int> dist(n+m, -1);
    queue<int> que;
    for(auto t: wzero){
        que.push(t);
        dist[t] = 0;
    }
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q]+1;
            que.push(nq);
        }
    }

    if(dist[m-1] != -1){
        cout << dist[m-1]/2 << endl;
    }else{
        cout << -1 << endl;
    }
    
    return 0;
}