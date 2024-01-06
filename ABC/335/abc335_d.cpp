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
// https://atcoder.jp/contests/abc335/tasks/abc335_d

int main(){
    int n; cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    ans[n/2][n/2] = -1;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int x = 0, y = 0, a = 2;
    ans[0][0] = 1;
    while(a <= n*n-1){
        rep(k, 0, 4){
            while(0 <= x+dx[k] && x+dx[k] < n && 0 <= y+dy[k] && y+dy[k] < n && ans[x+dx[k]][y+dy[k]] == 0){
                x += dx[k], y += dy[k];
                ans[x][y] = a;
                a++;
            }
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            if(ans[i][j] == -1) cout << 'T' << ' ';
            else cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    
    return 0;
}