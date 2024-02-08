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
// https://atcoder.jp/contests/arc169/tasks/arc169_c

int main(){
    int h, w, t; cin >> h >> w >> t;
    vector<string> s(h+2);
    rep(i, 0, w+2){
        s[0] += 'W';
        s[h+1] += 'W';
    }
    pair<ll, ll> start, goal;
    rep(i, 1, h+1){
        string s_; cin >> s_;
        s[i] = 'W'+s_+'W';
        rep(j, 1, w+1){
            if(s[i][j] == 'S') start = {i, j};
            if(s[i][j] == 'G') goal = {i, j};
        }
    }

    ll ok = 1, ng = 1e10;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
        que.push({0, start.first, start.second});
        vector<vector<ll>> dist(h+2, vector<ll>(w+2, 9e18));
        while(!que.empty()){
            auto [cur, x, y] = que.top(); que.pop();
            if(cur >= dist[x][y]) continue;
            dist[x][y] = cur;
            rep(i, 0, 4){
                ll nx = x+(i-1)%2, ny = y+(i-2)%2;
                if(s[nx][ny] == 'W') continue;
                ll d = 1;
                if(s[nx][ny] == '#') d = mid;
                que.push({dist[x][y]+d, nx, ny});
            }
        }

        if(dist[goal.first][goal.second] <= t) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}