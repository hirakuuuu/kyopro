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
    int h, w; cin >> h >> w;
    vector<vector<char>> s(h+2, vector<char>(w+2, '#'));
    int cnt = 0;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> s[i][j];
            if(s[i][j] == '#') cnt++;
        }
    }

    queue<pair<int, int>> que;
    que.push({1, 1});
    vector<vector<int>> dist(h+2, vector<int>(w+2, -1));
    dist[1][1] = 1;
    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(i, 0, 4){
            int nx = x+(i-2)%2, ny = y+(i-1)%2;
            if(s[nx][ny] == '#' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y]+1;
            que.push({nx, ny});
        }        
    }

    if(dist[h][w] == -1){
        cout << -1 << endl;
    }else{
        cout << h*w-cnt-dist[h][w] << endl;

    }
    
    return 0;
}