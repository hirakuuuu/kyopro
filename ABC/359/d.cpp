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

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> p(1<<k);
    rep(i, 0, 1<<k){
        string ss;
        rrep(j, k-1, 0) ss += 'A'+((i>>j)&1);
        string t = ss;
        reverse(t.begin(), t.end());
        if(ss == t) p[i] = 1;
    }

    vector<vector<mint>> dp(n+1, vector<mint>(1<<k));
    dp[0][0] = 1;
    rep(i, 0, n){
        if(s[i] == '?'){
            rep(j, 0, 1<<k){
                if(i >= k && p[j]) continue;
                rep(l, 0, 2){
                    int nxt = (j<<1)+l;
                    if(nxt >= 1<<k) nxt -= 1<<k;
                    if(!(i >= k && p[nxt])) dp[i+1][nxt] += dp[i][j];
                }
            }
        }else{
            rep(j, 0, 1<<k){
                if(i >= k && p[j]) continue;
                int nxt = (j<<1)+(s[i]-'A');
                if(nxt >= 1<<k) nxt -= (1<<k);
                if(i >= k && p[nxt]) continue;
                dp[i+1][nxt] += dp[i][j];
            }
        }
    }
    mint ans = 0;
    rep(i, 0, 1<<k){
        if(p[i]) continue;
        ans += dp[n][i];
    }
    cout << ans.val() << endl;
    
    return 0;
}