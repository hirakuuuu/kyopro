#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc067/tasks/arc078_b


vector<vector<int>> d(2, vector<int>(200005, -1));
vector<vector<int>> g(200005);
void bfs(int s, int w){
    queue<int> que;
    que.push(s);
    d[w][s] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(d[w][nq] >= 0) continue;
            d[w][nq] = d[w][q]+1;
            que.push(nq);
        }
    }
}

int main(){
    int n; cin >> n;
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1, 0);
    bfs(n, 1);
    int f = 0, s = 0;
    rep(i, 1, n+1){
        if(d[0][i] <= d[1][i]) f++;
        else s++;
    }
    if(f <= s) cout << "Snuke" << endl;
    else cout << "Fennec" << endl;    
    return 0;
}