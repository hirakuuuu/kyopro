#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tii tuple<int, int, int, int>
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
    vector<string> s(h+2);
    rep(i, 0, w+2){
        s[0] += '!';
        s[h+1] += '!';
    }
    rep(i, 1, h+1){
        string t; cin >> t;
        s[i] = '!'+t+'!';
    }

    vector<vector<int>> ok(5, vector<int>(4, -1));
    ok[0][2] = 2;
    ok[0][3] = 1;
    ok[1][1] = 0;
    ok[1][2] = 3;
    ok[2][0] = 0;
    ok[2][3] = 3;
    ok[3][0] = 1;
    ok[3][1] = 2;

    vector<vector<vector<int>>> dp(h+2, vector<vector<int>>(w+2, vector<int>(5, IINF)));
    dp[1][1][4] = 0;
    rep(i, 0, 4){
        dp[1][1][i] = 1;
    }
    priority_queue<tii, vector<tii>, greater<tii>> que;
    que.push({0, 1, 1, 4});
    rep(i, 0, 4){
        que.push({1, 1, 1, i});
    }
    while(!que.empty()){
        auto [cost, ch, cw, dir] = que.top(); que.pop();
        rep(i, 0, 4){
            int nh = ch+(i-1)%2, nw = cw+(i-2)%2;
            if(s[nh][nw] == '!') continue;
            if(s[nh][nw] == '.'){
                if(dp[nh][nw][4] > cost){
                    dp[nh][nw][4] = cost;
                    que.push({cost, nh, nw, 4});
                }
            }
            if(ok[dir][i] != -1){
                if(dp[nh][nw][ok[dir][i]] > cost){
                    dp[nh][nw][ok[dir][i]] = cost;
                    que.push({cost, nh, nw, ok[dir][i]});
                }
            }else{
                rep(j, 0, 4){
                    if(dp[nh][nw][j] > cost+1){
                        dp[nh][nw][j] = cost+1;
                        que.push({cost+1, nh, nw, j});
                    }
                }
            }
        }
    }
    cout << dp[h][w][4] << endl;
    return 0;
}