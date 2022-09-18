#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc269/tasks/abc269_d


int main(){
    int n; cin >> n;
    vector<vector<bool>> grid(2005, vector<bool>(2005));

    rep(i, 0, n){
        int x, y; cin >> x >> y;
        x += 1000;
        y += 1000;
        grid[x][y] = true;
    }

    vector<vector<bool>> seen(2005, vector<bool>(2005));

    vector<int> dx = {-1, -1, 0, 0, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 0, 1};

    int ans = 0;

    rep(i, 0, 2001){
        rep(j, 0, 2001){
            if(!grid[i][j] or seen[i][j]) continue;
            ans++;
            queue<pii> que;
            que.push({i, j});
            seen[i][j] = true;
            while(!que.empty()){
                pii q = que.front(); que.pop();
                rep(k, 0, 6){
                    int nx = q.first+dx[k], ny = q.second+dy[k];
                    if(nx < 0 or 2000 < nx or ny < 0 or 2000 < ny) continue;
                    if(grid[nx][ny] and !seen[nx][ny]){
                        seen[nx][ny] = true;
                        que.push({nx, ny});
                    }
                }
            }
        }
    }

    cout << ans << endl;
    

    
    return 0;
}