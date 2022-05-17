#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_u

/*
有向グラフで行き来できるかを判定　→ SCC(強連結成分分解)
・まず普通にDFSして帰りがけ順に頂点を記録
・次に全ての辺を逆にして、帰りがけ順が遅い方からDFSして、到達できる頂点の個数を数える
・このサイトがわかりやすかった
https://manabitimes.jp/math/1250
*/

vector<vector<int>> g1(100005), g2(100005);
vector<int> t, seen(100005, 0);

void dfs1(int pos){
    seen[pos] = 1;
    for(auto npos: g1[pos]){
        if(seen[npos]) continue;
        dfs1(npos);
    }
    t.push_back(pos);
}

void dfs2(int pos, ll &cnt){
    seen[pos] = 1;
    for(auto npos: g2[pos]){
        if(seen[npos]) continue;
        dfs2(npos, cnt);
    }
    cnt++;
}

int main(){
    int n, m; cin >> n >> m;
    map<pii, int> exist;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        if(exist[{a, b}]) continue;
        exist[{a, b}] = 1;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    rep(i, 1, n+1){
        if(seen[i]) continue;
        dfs1(i);
    }
    reverse(t.begin(), t.end());
    seen.assign(100005, 0);
    ll ans = 0, cnt = 0;
    for(auto tt: t){
        if(seen[tt]) continue;
        cnt = 0;
        dfs2(tt, cnt);
        ans += cnt*(cnt-1)/2;
    }
    cout << ans << endl;    
    return 0;
}