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
// https://atcoder.jp/contests/abc308/tasks/abc308_d

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> s(h+2, vector<char>(w+2, '#'));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> s[i][j];
        }
    }

    string snuke = "snuke";
    queue<pii> que;
    que.push({1, 1});
    vector<vector<bool>> reach(h+2, vector<bool>(w+2));
    reach[1][1] = true;
    while(!que.empty()){
        const auto [x, y] = que.front(); que.pop();
        rep(i, 0, 4){
            int nx = x+(i-1)%2, ny = y+(i-2)%2;
            if(reach[nx][ny]) continue;
            rep(j, 0, 5){
                if(snuke[j] == s[x][y] && snuke[(j+1)%5] == s[nx][ny]){
                    que.push({nx, ny});
                    reach[nx][ny] = true;
                }
            }
        }
    }

    if(reach[h][w]) cout << "Yes" << endl;
    else cout << "No" << endl;

    
    return 0;
}