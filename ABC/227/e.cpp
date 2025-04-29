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
    string s; cin >> s; 
    int n = (int)s.size();
    vector<vector<int>> pos(3);
    vector<int> c(3);
    rep(i, 0, n){
        if(s[i] == 'K') pos[0].push_back(i), c[0]++;
        if(s[i] == 'E') pos[1].push_back(i), c[1]++;
        if(s[i] == 'Y') pos[2].push_back(i), c[2]++;
    }
    int k; cin >> k;
    chmin(k, 500);

    vector dp(k+1, vector(n+1, vector(n+1, vector<ll>(n+1))));
    dp[0][0][0][0] = 1;
    rep(c1, 0, n+1){
        if(c[0] < c1) continue;
        rep(c2, 0, n+1){
            if(c[1] < c2) continue;
            rep(c3, 0, n+1){
                if(c[2] < c3) continue;

                // 次に追加する各文字の位置を求める
                vector<int> cnt(3);
                vector<int> nxt(3, -1);
                rep(i, 0, n){
                    if(s[i] == 'K'){
                        if(cnt[0] < c1) cnt[0]++;
                        else if(nxt[0] == -1 && cnt[0] == c1) nxt[0] = i-(cnt[0]+cnt[1]+cnt[2]);
                    }
                    if(s[i] == 'E'){
                        if(cnt[1] < c2) cnt[1]++;
                        else if(nxt[1] == -1 && cnt[1] == c2) nxt[1] = i-(cnt[0]+cnt[1]+cnt[2]);
                    }
                    if(s[i] == 'Y'){
                        if(cnt[2] < c3) cnt[2]++;
                        else if(nxt[2] == -1 && cnt[2] == c3) nxt[2] = i-(cnt[0]+cnt[1]+cnt[2]);
                    }
                }


                rep(i, 0, k+1){
                    if(dp[i][c1][c2][c3] == 0) continue;
                    if(nxt[0] != -1 && i+nxt[0] <= k){
                        dp[i+nxt[0]][c1+1][c2][c3] += dp[i][c1][c2][c3];
                    }
                    if(nxt[1] != -1 && i+nxt[1] <= k){
                        dp[i+nxt[1]][c1][c2+1][c3] += dp[i][c1][c2][c3];
                    }
                    if(nxt[2] != -1 && i+nxt[2] <= k){
                        dp[i+nxt[2]][c1][c2][c3+1] += dp[i][c1][c2][c3];
                    }
                }
            }
        }
    }

    ll ans = 0;
    rep(i, 0, k+1){
        ans += dp[i][c[0]][c[1]][c[2]];
    }
    cout << ans << endl;



    return 0;
}