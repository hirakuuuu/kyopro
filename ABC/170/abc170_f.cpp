#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll, ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc170/tasks/abc170_f

int main(){
    ll h, w, k; cin >> h >> w >> k;
    pll start, goal;
    cin >> start.first >> start.second;
    cin >> goal.first >> goal.second;

    vector<vector<char>> c(h+2, vector<char>(w+2, '@'));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> c[i][j];
        }
    }

    priority_queue<tll, vector<tll>, greater<tll>> que;
    rep(i, 0, 4) que.push({1, -k, start.first, start.second, i});
    const pll not_reached = {INF, INF};  
    vector<vector<vector<pll>>> dist(h+1, vector<vector<pll>>(w+1, vector<pll>(4, not_reached)));
    rep(i, 0, 4) dist[start.first][start.second][i] = {1, -k+1};

    while(!que.empty()){
        auto [cost, rest, px, py, dir] = que.top(); que.pop();
        if(dist[px][py][dir] < make_pair(cost, rest)) continue;
        rep(i, 0, 4){
            ll nx = px+(i-1)%2, ny = py+(i-2)%2;
            if(c[nx][ny] == '@') continue;
            pll nd = {cost, rest+1};
            if(i != dir || nd.second > 0){
                nd.first++;
                nd.second = -k+1;
            }
            if(dist[nx][ny][i] <= nd) continue;
            dist[nx][ny][i] = nd;

            que.push({nd.first, nd.second, nx, ny, i});
        }
    }

    ll ans = INF;
    rep(i, 0, 4) chmin(ans, dist[goal.first][goal.second][i].first);

    // rep(i, 1, h+1){
    //     rep(j, 1, w+1){
    //         ll tmp = INF;
    //         rep(l, 0, 4){
    //             chmin(tmp, dist[i][j][l].first);
    //         }
    //         cout << tmp << ' ';
    //     }
    //     cout << endl;
    // }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}