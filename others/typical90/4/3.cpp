#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_c

/*
木構造の最長パス　→　dfsを2回やる
・始点をノード１にしてdfsを行い, 最も遠くにあるノードの番号を取得
・その点を始点に再びdfsを行い，最も遠くにあるノードとの距離が最長パスである
・これに１を足して出力
*/

int n;
vector<int> dist(100005);
vector<vector<int>> g(100005);
void dfs(int s, int pre){
    for(auto ns: g[s]){
        if(ns == pre) continue;
        dist[ns] = dist[s]+1;
        dfs(ns, s);
    }
}

int max_path(int s){
    dist[s] = 0;
    dfs(s, 0);
    int max_d = 0, ns = 0;
    rep(i, 1, n+1){
        if(max_d < dist[i]){
            max_d = dist[i];
            ns = i;
        }
    }
    return ns;
}

int main(){
    cin >> n;
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int s = max_path(1);
    int t = max_path(s);

    cout << dist[t]+1 << endl;

    return 0;
}