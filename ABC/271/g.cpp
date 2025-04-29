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

int main(){
    ll n; cin >> n;
    int x, y; cin >> x >> y;
    mint px = x, py = y;
    px /= 100, py /= 100;
    string s; cin >> s;

    vector<vector<vector<mint>>> dp(61, vector<vector<mint>>(24, vector<mint>(24)));
    mint pr_no_access = 1;
    rep(i, 0, 24){
        if(s[i] == 'T') pr_no_access *= (mint(1)-px);
        if(s[i] == 'A') pr_no_access *= (mint(1)-py);
    }

    rep(j, 0, 24){
        // 今 j 時の直前で，1 回目のアクセスが k 時になる確率を求める
        mint pr_pre = 1;
        for(int k = j; k < j+24; k++){
            if(s[k%24] == 'T'){
                dp[0][j][k%24] = (pr_pre*px)/(mint(1)-pr_no_access);
                pr_pre *= mint(1-px);
            }
            if(s[k%24] == 'A'){
                dp[0][j][k%24] = (pr_pre*py)/(mint(1)-pr_no_access);
                pr_pre *= mint(1-py);
            }
        }
    }


    rep(i, 1, 61){
        rep(j, 0, 24){
            rep(k, 0, 24){
                rep(l, 0, 24){
                    dp[i][j][k] += dp[i-1][j][l]*dp[i-1][(l+1)%24][k];
                }
            }
        }
    }

    vector<mint> pr(24);
    pr[23] = 1;
    rep(i, 0, 61){
        if((n>>i)&1){
            vector<mint> npr(24);
            rep(j, 0, 24){
                rep(k, 0, 24){
                    npr[j] += pr[k]*dp[i][(k+1)%24][j];
                }
            }
            swap(pr, npr);
        }
    }

    mint ans = 0;
    rep(j, 0, 24){
        if(s[j] == 'A') ans += pr[j];
    }
    cout << ans.val() << endl;
    return 0;
}