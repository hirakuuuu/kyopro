#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string ABC = "ABC";
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = (int)s.size();
        int k; cin >> k;

        vector<int> in_abc(n);
        rep(i, 0, n-2){
            if(s.substr(i, 3) == ABC){
                in_abc[i] = 1;
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(k+1, IINF));
        dp[0][0] = 0;
        rep(i, 0, n){
            if(i+1 >= 8){
                // ABC**ABC
                int diff = 0;
                rep(j, 0, 3) if(s[i-7+j] != ABC[j]) diff++;
                rep(j, 0, 3) if(s[i-2+j] != ABC[j]) diff++;
                int cnt = 0;
                rep(j, max(0, i-9), i+1) if(in_abc[j]) cnt++;
                if(cnt-2 > 0) continue;
                rep(l, 0, k+1){
                    if(inr(0, l-cnt+2, k+1)) chmin(dp[i+1][l-cnt+2], dp[i-7][l]+diff);
                }
            }
            if(i+1 >= 7){
                // ABC*ABC
                int diff = 0;
                rep(j, 0, 3) if(s[i-6+j] != ABC[j]) diff++;
                rep(j, 0, 3) if(s[i-2+j] != ABC[j]) diff++;
                int cnt = 0;
                rep(j, max(0, i-8), i+1) if(in_abc[j]) cnt++;
                if(cnt-2 > 0) continue;
                rep(l, 0, k+1){
                    if(inr(0, l-cnt+2, k+1)) chmin(dp[i+1][l-cnt+2], dp[i-6][l]+diff);
                }
            }
            if(i+1 >= 6){
                // ABCABC
                int diff = 0;
                rep(j, 0, 3) if(s[i-5+j] != ABC[j]) diff++;
                rep(j, 0, 3) if(s[i-2+j] != ABC[j]) diff++;
                int cnt = 0;
                rep(j, max(0, i-7), i+1) if(in_abc[j]) cnt++;
                // cout << i << ' ' << cnt << endl;
                if(cnt-2 > 0) continue;
                rep(l, 0, k+1){
                    if(inr(0, l-cnt+2, k+1)) chmin(dp[i+1][l-cnt+2], dp[i-5][l]+diff);
                }
            }
            if(i+1 >= 3){
                // ABC
                int diff = 0;
                rep(j, 0, 3) if(s[i-2+j] != ABC[j]) diff++;
                int cnt = 0;
                rep(j, max(0, i-4), i+1) if(in_abc[j]) cnt++;
                if(cnt-1 > 0) continue;
                rep(l, 0, k+1){
                    if(inr(0, l-cnt+1, k+1)) chmin(dp[i+1][l-cnt+1], dp[i-2][l]+diff);
                }
            }

            // rep(l, 0, k+1){
            //     cout << dp[i+1][l] << ' ';
            // }
            // cout << endl;
        }

        int ans = IINF;
        rep(i, 1, n+1){
            chmin(ans, dp[i][k]);
        }
        if(ans == IINF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}