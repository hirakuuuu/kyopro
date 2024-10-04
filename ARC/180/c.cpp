#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
dp[i][j] := i 番目までを決めて, a[i]=j となる通り数（j != a[i]）
j != a[i] という制約から、i 番目には操作が行われたとする。

j != 0 の場合：
- 次に操作を行う数について、j 足されるので, 制約が保たれる。
j == 0 の場合：
- 次に操作を行う数は数字が変わらない
- その次の数字が変わるので、その前に選べる数字を全探索すれば良い
- ここで、複数の数字を選ぶ可能性が考えられるが、次に始めて数字が変わる箇所を選ぶので、1つだけ考えれば良い。

*/

int main(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    int offset = 1000;
    vector<vector<mint>> dp(n+1, vector<mint>(2001));
    dp[0][offset] = 1;
    rep(i, 0, n+1){
        rep(j, -10*i, 10*i+1){
            if(j != 0){
                rep(k, i+1, n+1){
                    dp[k][j+a[k]+offset] += dp[i][j+offset];
                }
            }else{
                vector<bool> use(21);
                rep(k, i+1, n+1){
                    if(a[k] == 0) continue;
                    if(use[a[k]+10]) continue;
                    int nj = j+a[k];
                    use[a[k]+10] = true;
                    rep(l, k+1, n+1){
                        dp[l][nj+a[l]+offset] += dp[i][j+offset];
                    }
                }
            }
        }
    }

    mint ans = 0;
    rep(i, 0, n+1){
        rep(j, -1000, 1001){
            ans += dp[i][j+offset];
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}