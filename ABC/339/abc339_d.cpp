#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc339/tasks/abc339_d

int dist[65][65][65][65];

int main(){
    int n; cin >> n;
    vector<string> s(n+2);
    rep(i, 0, n+2){
        s[0] += '#';
        s[n+1] += '#';
    }
    rep(i, 1, n+1){
        string t; cin >> t;
        s[i] = '#'+t+'#';
    }
    vector<pair<int, int>> p;
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            if(s[i][j] == 'P'){
                p.push_back({i, j});
            }
        }
    }

    rep(i, 1, n+1) rep(j, 1, n+1) rep(k, 1, n+1) rep(l, 1, n+1){
        dist[i][j][k][l] = -1;
    }
    queue<tuple<pair<int, int>, pair<int, int>>> que;
    rep(i, 0, 4){
        que.push({p[0], p[1]});
        dist[p[0].first][p[0].second][p[1].first][p[1].second] = 0;
    }
    while(!que.empty()){
        auto [p1, p2] = que.front(); que.pop();
        auto [x1, y1] = p1;
        auto [x2, y2] = p2;
        rep(i, 0, 4){
            int nx1 = x1+(i-1)%2, ny1 = y1+(i-2)%2;
            int nx2 = x2+(i-1)%2, ny2 = y2+(i-2)%2;
            if(s[nx1][ny1] == '#'){
                nx1 = x1, ny1 = y1;
            }
            if(s[nx2][ny2] == '#'){
                nx2 = x2, ny2 = y2;
            }
            if(dist[nx1][ny1][nx2][ny2] == -1){
                dist[nx1][ny1][nx2][ny2] = dist[x1][y1][x2][y2]+1;
                if(nx1 == nx2 && ny1 == ny2){
                    cout << dist[nx1][ny1][nx2][ny2] << endl;
                    return 0;
                }
                que.push({{nx1, ny1}, {nx2, ny2}});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}