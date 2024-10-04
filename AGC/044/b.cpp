#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> p(n*n);
    rep(i, 0, n*n){
        cin >> p[i];
        p[i]--;
    }

    // 席がすべて埋まっている下で、外周からの距離の最小値を BFS で求める
    vector<vector<int>> d(n, vector<int>(n, IINF));
    vector<vector<int>> s(n, vector<int>(n, 1));
    {
        deque<int> que;
        rep(i, 0, n){
            d[i][0] = 0; que.push_back(i*n);
            d[i][n-1] = 0; que.push_back(i*n+n-1);
            d[0][i] = 0; que.push_back(i);
            d[n-1][i] = 0; que.push_back(n*(n-1)+i);
        }
        while(!que.empty()){
            auto pos = que.front(); que.pop_front();
            int x = pos/n, y = pos%n, dist = d[x][y];
            rep(k, 0, 4){
                int nx = x+(k-1)%2, ny = y+(k-2)%2;
                if(!inr(0, nx, n) || !inr(0, ny, n)) continue;
                if(d[nx][ny] != IINF) continue;
                d[nx][ny] = dist+s[nx][ny];
                que.push_back(nx*n+ny);
            }
        }
    }

    int ans = 0;
    rep(i, 0, n*n){
        ans += d[p[i]/n][p[i]%n];
        s[p[i]/n][p[i]%n] = 0;

        // 差分を更新する
        deque<int> que;
        que.push_back(p[i]);
        while(!que.empty()){
            auto pos = que.front(); que.pop_front();
            int x = pos/n, y = pos%n;
            rep(k, 0, 4){
                int nx = x+(k-1)%2, ny = y+(k-2)%2;
                if(!inr(0, nx, n) || !inr(0, ny, n)) continue;
                if(d[nx][ny] <= d[x][y]+s[x][y]) continue;
                d[nx][ny] = d[x][y]+s[x][y];
                if(s[x][y]) que.push_back(nx*n+ny);
                else que.push_front(nx*n+ny);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}