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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = "#"+s;
    vector<int> pre(n+1, -1);
    vector<int> kind(n+1);
    rep(i, 1, n+1){
        rep(j, 1, i){
            if(s[i] == s[j]) pre[i] = j;
        }
    }
    rrep(i, n-1, 0){
        set<char> st;
        rrep(j, n, i+1) st.insert(s[j]);
        kind[i] = (int)st.size();
    }
    // rep(i, 0, n+1){
    //     cout << kind[i] << ' ';
    // }
    // cout << endl;

    mint p = 0;
    rrep(len, n, 0){
        vector<vector<vector<mint>>> dp(m+1, vector<vector<mint>>(n+1, vector<mint>(n+1)));
        dp[0][0][0] = 1;
        rep(i, 0, m){
            rep(j, 0, n+1){
                rep(l, 0, n+1){
                    dp[i+1][j][l] += dp[i][j][l]*(26-kind[l]);
                    if(j+1 <= n){
                        rep(k, l+1, n+1){
                            if(inr(l+1, pre[k], k)) continue;
                            dp[i+1][j+1][k] += dp[i][j][l];
                        }
                    }
                }
            }
        }
        mint ans = 0;
        rrep(i, n, len) ans += dp[m][len][i];
        cout << ans.val() << endl;
        p = ans;
    }
    
    return 0;
}