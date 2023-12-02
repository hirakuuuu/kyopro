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
    vector<vector<char>> a(h+2, vector<char>(w+2, '#'));
    int sh, sw, gh, gw;
    vector<bool> seen(26);
    vector<vector<pair<int, int>>> pos(26);
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                sh = i, sw = j;
            }
            if(a[i][j] == 'G'){
                gh = i, gw = j;
            }
            if(0 <= a[i][j]-'a' && a[i][j]-'a' < 26){
                pos[a[i][j]-'a'].push_back({i, j});
            }
        }
    }

    vector<vector<int>> dist(h+2, vector<int>(w+2, IINF));
    dist[sh][sw] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
    que.push({0, sh, sw});
    while(!que.empty()){
        auto [d, cx, cy] = que.top(); que.pop();
        if(0 <= a[cx][cy]-'a' && a[cx][cy]-'a' < 26 && !seen[a[cx][cy]-'a']){
            int t = a[cx][cy]-'a';
            seen[t] = true;
            for(auto [x, y]: pos[t]){
                if(dist[x][y] != IINF) continue;
                dist[x][y] = d+1;
                que.push({dist[x][y], x, y});
            }
        }
        rep(i, 0, 4){
            int nx = cx+(i-1)%2, ny = cy+(i-2)%2;
            if(a[nx][ny] == '#' || dist[nx][ny] != IINF) continue;
            dist[nx][ny] = dist[cx][cy]+1;
            que.push({dist[nx][ny], nx, ny});
        }
    }

    if(dist[gh][gw] == IINF) cout << -1 << endl;
    else cout << dist[gh][gw] << endl;

    
    return 0;
}    