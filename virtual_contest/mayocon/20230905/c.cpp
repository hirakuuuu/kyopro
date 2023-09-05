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

int main(){
    int h, w; cin >> h >> w;
    vector<string> c(h);
    rep(i, 0, h) cin >> c[i];

    queue<pair<int, int>> que;
    que.push({0, 0});
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0] = 1;
    while(!que.empty()){
        auto [i, j] = que.front(); que.pop();
        if(i+1 < h && c[i+1][j] == '.' && dist[i+1][j] == -1){
            dist[i+1][j] = dist[i][j]+1;
            que.push({i+1, j});
        }
        if(j+1 < w && c[i][j+1] == '.' && dist[i][j+1] == -1){
            dist[i][j+1] = dist[i][j]+1;
            que.push({i, j+1});
        }
    }

    int ans = 0;
    rep(i, 0, h){
        rep(j, 0, w){
            chmax(ans, dist[i][j]);
        }
    }

    cout << ans << endl;
    
    return 0;
}