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
// https://atcoder.jp/contests/abc319/tasks/abc319_c

int main(){
    vector<int> jun(9);
    rep(i, 0, 9) jun[i] = i;
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 0, 3){
        rep(j, 0, 3) cin >> c[i][j];
    }
    
    int cnt = 0;
    do{
        vector<vector<bool>> seen(3, vector<bool>(3));
        bool f = true;
        rep(i, 0, 9){
            int x = jun[i]/3, y = jun[i]%3;
            // 縦
            if(seen[(x+1)%3][y] && seen[(x+2)%3][y] && c[(x+1)%3][y] == c[(x+2)%3][y]) f = false;
            // 横
            if(seen[x][(y+1)%3] && seen[x][(y+2)%3] && c[x][(y+1)%3] == c[x][(y+2)%3]) f = false;
            // 斜め
            if(abs(x-y) == 0 && seen[(x+1)%3][(y+1)%3] && seen[(x+2)%3][(y+2)%3] && c[(x+1)%3][(y+1)%3] == c[(x+2)%3][(y+2)%3]) f = false;
            if((x*y == 1 || abs(x-y) == 2) && seen[(x+1)%3][(y+2)%3] && seen[(x+2)%3][(y+1)%3] && c[(x+1)%3][(y+2)%3] == c[(x+2)%3][(y+1)%3]) f = false;
            seen[x][y] = true;
        }
        if(f) cnt++;
    }while(next_permutation(jun.begin(), jun.end()));

    int bunbo = 1;
    rep(i, 2, 10) bunbo *= i;
    printf("%.10f\n", (double)cnt/bunbo);
    return 0;
}