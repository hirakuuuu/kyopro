#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc286/tasks/abc286_e

vector<vector<int>> g(305);
int main(){
    ll n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, n){
            if(s[j] == 'Y') g[i+1].push_back(j+1);
        }
    }

    vector<vector<ll>> val(n+1, vector<ll>(n+1, -1));
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, -1));
    rep(i, 1, n+1){
        queue<int> que;
        que.push(i);
        val[i][i] = a[i];
        dist[i][i] = 0;
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(const auto &nq: g[q]){
                if(dist[i][nq] == -1 or dist[i][nq] == dist[i][q]+1){
                    chmax(val[i][nq], val[i][q]+a[nq]);
                    if(dist[i][nq] == -1){
                        dist[i][nq] = dist[i][q]+1;
                        que.push(nq);
                    }
                }
            }
        }
    }

    int q; cin >> q;
    while(q--){
        int s, t; cin >> s >> t;
        if(val[s][t] == -1) cout << "Impossible" << endl;
        else cout << dist[s][t] << ' ' << val[s][t] << endl;
    }



    
    return 0;
}