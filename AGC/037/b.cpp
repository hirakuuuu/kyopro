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
前から貪欲に取って行くのが最小値を実現する
それを応用すると、結局ある時点で R, G, B の個数を x <= y <= z とすると, 
GB が y-x 個, B が z-y 個ある状態になる. 
このように, 2つの文字が余っていて, 1文字 or 2文字の状態になっているので, 
次の文字に対する挙動が一意に定まる.
これをＤＰすれば解ける.
*/


int main(){
    const string RGB="RGB";
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> dp(6);
    if(s[0] == 'R') dp[0] = 1;
    if(s[0] == 'G') dp[1] = 1;
    if(s[0] == 'B') dp[2] = 1;
    // RG: 3, GB: 4, BR: 5
    mint ans = 1;
    rep(i, 1, 3*n){
        if(s[i] == 'R'){
            if(dp[4] > 0){ ans *= dp[4]; dp[4]--; }
            else if(dp[1] > 0){ ans *= dp[1]; dp[1]--; dp[3]++; }
            else if(dp[2] > 0){ ans *= dp[2]; dp[2]--; dp[5]++; }
            else{ dp[0]++; }
        }else if(s[i] == 'G'){
            if(dp[5] > 0){ ans *= dp[5]; dp[5]--; }
            else if(dp[0] > 0){ ans *= dp[0]; dp[0]--; dp[3]++; }
            else if(dp[2] > 0){ ans *= dp[2]; dp[2]--; dp[4]++; }
            else{ dp[1]++; }
        }else if(s[i] == 'B'){
            if(dp[3] > 0){ ans *= dp[3]; dp[3]--; }
            else if(dp[0] > 0){ ans *= dp[0]; dp[0]--; dp[5]++; }
            else if(dp[1] > 0){ ans *= dp[1]; dp[1]--; dp[4]++; }
            else{ dp[2]++; }
        }
    }
    rep(i, 1, n+1) ans *= i;
    cout << ans.val() << endl;

    return 0;
}