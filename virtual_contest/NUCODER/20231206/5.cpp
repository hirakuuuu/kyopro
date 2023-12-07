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
// 


int main(){
    int n; cin >> n;
    int ax, ay; cin >> ax >> ay;
    int bx, by; cin >> bx >> by;
    vector<int> dx = {1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1};
    vector<vector<char>> s(n+2, vector<char>(n+2, '#'));
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            cin >> s[i][j];
        }
    }

    vector<vector<vector<int>>> dist(4, vector<vector<int>>(n+2, vector<int>(n+2, IINF)));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> que;
    rep(i, 0, 4){
        que.push({1, i, ax, ay});
    }
    while(!que.empty()){
        auto [d, i, cx, cy] = que.top(); que.pop();
        if(dist[i][cx][cy] <= d) continue;
        dist[i][cx][cy] = d;
        rep(j, 0, 4){
            int nx = cx+dx[j], ny = cy+dy[j];
            if(s[nx][ny] == '#') continue;
            if(dist[j][nx][ny] <= d) continue;
            if(i == j) que.push({d, j, nx, ny});
            else que.push({d+1, j, nx, ny});
        }
    }

    int ans = IINF;
    rep(i, 0, 4){
        chmin(ans, dist[i][bx][by]);
    }
    if(ans != IINF) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}