#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_m

/*
1からk、kからnの最短距離が分かればよい　→　ダイクストラ
・前計算として1，ｎを始点とした各点までの最短距離を計算しておく
・後は順番に（1からkの距離）＋（ｎからkの距離）を出力
・ダイクストラの実装はややこしい
*/

vector<pll> g[200005];
vector<ll> f_1(200005, -1), f_n(200005, -1);

void dijk(int s, vector<ll> &f){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    que.push({0, s});
    while(!que.empty()){
        pll q = que.top(); que.pop();
        if(f[q.second] < 0) f[q.second] = q.first;
        for(auto nq: g[q.second]){
            if(f[nq.second] >= 0) continue;
            que.push({f[q.second]+nq.first, nq.second});
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    dijk(1, f_1);
    dijk(n, f_n);

    rep(i, 1, n+1){
        cout << f_1[i]+f_n[i] << endl;
    }

    return 0;
}