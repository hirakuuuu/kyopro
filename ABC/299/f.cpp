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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- 部分文字列を取り出すときに，左から優先的に選ぶようにすると，重複を除ける典型
- 文字列を前半と後半に分ける位置を全探索して，前半の最後の文字が使われた文字列の個数を数える
*/

int main(){
    string s; cin >> s;
    int n = (int)s.size();

    mint ans = 0;
    rep(m, 1, n){
        string sl = s.substr(0, m);
        string sr = s.substr(m);
        vector<int> prel(sl.size()+1), prer(sr.size()+1);
        {
            vector<int> pre(26);
            rep(i, 1, sl.size()+1){
                prel[i] = pre[sl[i-1]-'a'];
                pre[sl[i-1]-'a'] = i;
            }
        }
        {
            vector<int> pre(26);
            rep(i, 1, sr.size()+1){
                prer[i] = pre[sr[i-1]-'a'];
                pre[sr[i-1]-'a'] = i;
            }
        }
        vector<vector<mint>> dp(sl.size()+1, vector<mint>(sr.size()+1));
        dp[0][0] = 1;
        rep(i, 1, sl.size()+1){
            rep(j, 1, sr.size()+1){
                if(sl[i-1] != sr[j-1]) continue;
                rep(pi, prel[i], i) rep(pj, prer[j], j){
                    dp[i][j] += dp[pi][pj];
                }
            }
        }

        rep(i, 0, sr.size()+1){
            ans += dp[m][i];
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}