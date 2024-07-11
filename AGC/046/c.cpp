#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
操作回数 k は文字列の長さ分程度あれば十分
0で文字列を区切ることを考えると, 各区間について、１をより左の区間に加えるという操作に言い換えられる

dp[i][j][k] := 区間iまでに 1 が j 個あって, 操作をk回行ったときに作れる文字列の個数
遷移は 現在見ている区間で 1 の個数が x 個増えるとすると
その区間に移動させる操作の回数が自明に分かる. (増えた分だけカウントすればよい, 減った分はそれより前でカウントしているので)


*/

int main(){
    string s; 
    int k; cin >> s >> k;
    s += '0';
    int n = (int)s.size();
    vector<int> a;
    int t = 0, ones = 0;
    rep(i, 0, n){
        if(s[i] == '0'){
            a.push_back(t);
            t = 0;
        }else{
            t++;
            ones++;
        }
    }
    int len = (int)a.size();
    vector<int> acc(len+1);
    rep(i, 0, len) acc[i+1] = acc[i]+a[i]; 
    vector<vector<vector<mint>>> dp(len+1, vector<vector<mint>>(n+1, vector<mint>(n+1)));
    dp[0][0][0] = 1;
    rep(i, 0, len){
        rep(j, 0, n+1){
            rep(l, 0, n+1){
                if(dp[i][j][l] == 0) continue;
                rep(x, 0, n-j+1){
                    if(j+x < acc[i+1]) continue;
                    dp[i+1][j+x][l+max(x-a[i], 0)] += dp[i][j][l];
                }
            }
        }
    }
    mint ans = 0;
    rep(i, 0, min(n+1, k+1)){
        ans += dp[len][ones][i];
    }
    cout << ans.val() << endl;
    return 0;
}