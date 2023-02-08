#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_z

/*
木は必ず2部グラフ
・適当に1つの頂点から始めて、1か0をラベリング
・n/2以上含む方からn/2個出力
*/

vector<vector<int>> g(100005);
vector<vector<int>> label(2);

void dfs(int pos, int pre, int l=0){
    label[l].push_back(pos);
    for(auto npos: g[pos]){
        if(npos == pre) continue;
        dfs(npos, pos, 1-l);
    }
}

int main(){
    int n; cin >> n;
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);
    if(label[0].size() >= n/2){
        rep(i, 0, n/2) cout << label[0][i] << " ";
    }else{
        rep(i, 0, n/2) cout << label[1][i] << " ";
    }
    cout << endl;

    return 0;
}