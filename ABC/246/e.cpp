#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc246/tasks/abc246_e

int main(){
    int n; cin >> n;
    int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
    vector<vector<char>> field(n+2, vector<char>(n+2, '#'));
    rep(i, 1, n+1){
        rep(j, 1, n+1) cin >> field[i][j];
    }
    vector<vector<vector<int>>> d(n+2, vector<vector<int>>(n+2, vector<int>(4, 1000000007)));
    vector<int> dx={-1, 1, 1, -1}, dy = {1, 1, -1, -1};
    queue<pii> que;
    rep(i, 0, 4) d[ax][ay][i] = 1;
    que.push({ax, ay});
    while(!que.empty()){
        pii q = que.front(); que.pop();
        rep(i, 0, 4){
            int nx = q.first+dx[i], ny = q.second+dy[i];
            if(field[nx][ny] == '#' or d[nx][ny][i] <= d[q.first][q.second][i]) continue;
            d[nx][ny][i] = d[q.first][q.second][i];
            rep(j, 0, 4){
                d[nx][ny][j] = min(d[nx][ny][j], d[nx][ny][i]+1);
            }
            que.push({nx, ny});
        }
    }
    int ans = 1000000007;
    rep(i, 0, 4) ans = min(ans, d[bx][by][i]);
    if(ans == 1000000007) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}