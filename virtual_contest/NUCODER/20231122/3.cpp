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
    int h, w, n, m; cin >> h >> w >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    vector<vector<int>> s(h+2, vector<int>(w+2, 2));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            s[i][j] = 0;
        }
    }
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        s[a[i]][b[i]] = 1;
    }
    rep(i, 0, m){
        cin >> c[i] >> d[i];
        s[c[i]][d[i]] = 2;
    }

    queue<tuple<int, int, int>> que;
    vector<vector<vector<int>>> l(h+2, vector<vector<int>>(w+2, vector<int>(4)));
    rep(i, 0, n){
        rep(j, 0, 4){
            que.push({a[i], b[i], j});
            l[a[i]][b[i]][j] = 1;
        }
    }

    while(!que.empty()){
        auto [x, y, t] = que.front(); que.pop();
        int nx = x+(t-1)%2, ny = y+(t-2)%2;
        if(l[nx][ny][t] || s[nx][ny] == 2) continue;
        l[nx][ny][t] = 1;
        que.push({nx, ny, t});
    }
    int ans = 0;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            int f = 0;
            rep(k, 0, 4) f += l[i][j][k];
            if(f) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}