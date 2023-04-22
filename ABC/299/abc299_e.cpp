#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc299/tasks/abc299_e

vector<vector<int>> g(2005);

// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<int> bfs(int s){
    vector<int> dist(2005, -1);
    queue<int> que;
    que.push(s);
    dist[s] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] == -1){
                dist[nq] = dist[q]+1;
                que.push(nq);
            }
        }
    }
    return dist;
}

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int k; cin >> k;
    vector<int> p(k), d(k);
    vector<vector<int>> dist_p(k);
    rep(i, 0, k){
        cin >> p[i] >> d[i];
        dist_p[i] = bfs(p[i]);
    }

    vector<vector<bool>> is_min_d(n+1, vector<bool>(n+1));
    vector<bool> cant(n+1);
    rep(i, 0, k){
        rep(j, 1, n+1){
            if(dist_p[i][j] < d[i]) cant[j] = true;
        }
    }

    vector<int> ans(n+1);
    if(k == 0){
        rep(i, 1, n+1) ans[i] = 1;
    }
    rep(i, 0, k){
        bool ff = false;
        rep(j, 1, n+1){
            if(dist_p[i][j] == d[i] and !cant[j]){
                ff = true;
                ans[j] = 1;
            }
        }
        if(!ff){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i, 1, n+1) cout << ans[i];
    cout << endl;
    
    
    return 0;
}