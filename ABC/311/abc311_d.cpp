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
// https://atcoder.jp/contests/abc311/tasks/abc311_d

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    queue<tuple<int, int, int>> que;
    que.push({1, 1, 2});
    que.push({1, 1, 3});

    vector<vector<vector<bool>>> reach(n, vector<vector<bool>>(m, vector<bool>(4)));
    reach[1][1][2] = reach[1][1][3] = true;
    while(!que.empty()){
        auto [x, y, d] = que.front(); que.pop();
        reach[x][y][d] = true;
        int nx = x+dx[d], ny = y+dy[d];
        if(s[nx][ny] == '.'){
            if(reach[nx][ny][d]) continue;
            reach[nx][ny][d] = true;
            que.push({nx, ny, d});
        }else{
            rep(j, 0, 4){
                if(reach[x][y][j]) continue;
                reach[x][y][j] = true;
                que.push({x, y, j});
            }
        }
    }

    int ans = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            rep(d, 0, 4){
                if(reach[i][j][d]){
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}