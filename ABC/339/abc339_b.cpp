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
// https://atcoder.jp/contests/abc339/tasks/abc339_b

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<vector<int>> c(h, vector<int>(w));
    int x = 0, y = 0;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int d = 0;
    rep(_, 0, n){
        if(c[x][y] == 0){
            c[x][y] = 1;
            d = (d+1)%4;
        }else{
            c[x][y] = 0;
            d = (d+3)%4;
        }
        x = (x+dx[d]+h)%h;
        y = (y+dy[d]+w)%w;

    }
    rep(i, 0, h){
        rep(j, 0, w){
            if(c[i][j] == 0) cout << '.';
            if(c[i][j] == 1) cout << '#';
        }
        cout << endl;
    }
    
    return 0;
}