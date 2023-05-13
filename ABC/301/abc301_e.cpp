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
// https://atcoder.jp/contests/abc301/tasks/abc301_e

vector<vector<char>> a(310, vector<char>(305));

int main(){
    int h, w; cin >> h >> w;
    int t; cin >> t;
    
    vector<pii> grid;
    rep(i, 1, h+1){
        rep(j, 1, w+1) cin >> a[i][j];
    }
    rep(i, 0, h+2) a[i][0] = a[i][w+1] = '#';
    rep(i, 0, w+2) a[0][i] = a[h+1][i] = '#';
    rep(i, 1, h+1) rep(j, 1, w+1){
        if(a[i][j] == 'S') grid.push_back({i, j});
    }
    rep(i, 1, h+1) rep(j, 1, w+1){
        if(a[i][j] == 'o') grid.push_back({i, j});
    }
    rep(i, 1, h+1) rep(j, 1, w+1){
        if(a[i][j] == 'G') grid.push_back({i, j});
    }
    int b = grid.size();
    vector<vector<vector<int>>> dist(b);
    rep(i, 0, b){
        queue<pii> que;
        que.push(grid[i]);
        vector<vector<int>> d(h+2, vector<int>(w+2, iinf));
        d[grid[i].first][grid[i].second] = 0;
        while(!que.empty()){
            pii q = que.front(); que.pop();
            int x = q.first, y = q.second;
            rep(j, 0, 4){
                int nx = x+(j-1)%2, ny = y+(j-2)%2;
                if(a[nx][ny] != '#' and d[nx][ny] == iinf){
                    d[nx][ny] = d[x][y]+1;
                    que.push({nx, ny});
                }
            }
        }
        dist[i] = d;
    }

    vector<vector<int>> dp((1<<b),vector<int>(b, iinf));
    dp[1][0] = 0;
    rep(i, 1, (1<<b)){
        rep(j, 0, b){
            if((i&(1<<j)) == 0){
                rep(k, 0, b){
                    if((i&(1<<k)) > 0){
                        chmin(dp[i+(1<<j)][j], dp[i][k]+dist[k][grid[j].first][grid[j].second]);
                    }
                }
            }
        }
    }

    int ans = -1;
    rep(i, (1<<(b-1))+1, (1<<b)){
        if(dp[i][b-1] <= t){
            int cnt = 0;
            rep(j, 1, b-1) cnt += (i&(1<<j)) > 0;
            chmax(ans, cnt);
        }
    }
    cout << ans << endl;










    
    return 0;
}