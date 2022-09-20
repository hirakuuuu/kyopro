#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/aising2019/tasks/aising2019_c

int h, w;
vector<string> s(405); 
vector<vector<bool>> seen(405, vector<bool>(405));
vector<int> dh = {1, 0, -1, 0};
vector<int> dw = {0, 1, 0, -1};

bool include(int ch, int cw){
    return (0 <= ch and ch < h and 0 <= cw and cw < w);
}

pll dfs(int x, int y){
    seen[x][y] = true;

    ll a = 1, b = 0;

    rep(i, 0, 4){
        int nx = x+dh[i], ny = y+dw[i];
        if(include(nx, ny) and !seen[nx][ny] and s[x][y] != s[nx][ny]){
            pll p = dfs(nx, ny);
            a += p.second;
            b += p.first;
        }
    }

    return {a, b};
}

int main(){
    cin >> h >> w;
    rep(i, 0, h){
        cin >> s[i];
    }

    ll ans = 0;

    rep(i, 0, h){
        rep(j, 0, w){
            if(seen[i][j]) continue;
            pll p = dfs(i, j);
            ans += p.first*p.second;
        }
    }

    cout << ans << endl;
    return 0;
}