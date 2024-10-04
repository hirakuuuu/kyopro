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
    int n, d; cin >> n >> d;
    vector<int> p(n), q(n);
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> q[i];

    vector<vector<mint>> dp(d+1, vector<mint>(d+1));
    dp[0][0] = 1;
    rep(i, 0, n){
        vector<vector<mint>> s1(d+1, vector<mint>(d+1)); // 右下方向の累積和
        swap(s1, dp);
        vector<vector<mint>> s2 = s1; // 左下方向の累積和
        rep(i, 0, d) rep(j, 0, d) s1[i+1][j+1] += s1[i][j];
        rep(i, 0, d) rep(j, 0, d) s2[i+1][j] += s2[i][j+1];
        int w = abs(p[i]-q[i]);
        auto sum1 = [&](int j, int k) -> mint { // (j, k) から 左上に向かった時の累積和（右下方向の累積和から求まる）
            if(j < 0 || k < 0) return 0; // 始点がはみ出てたら0
            return s1[j][k];
        };
        auto sum2 = [&](int sj, int sk, int u) -> mint { // (j, k) から 左下に向かったときの u 個分の累積和（はみ出た分は補正する）
            int tj = sj-u-1, tk = sk+u+1;
            if(sk < 0){
                sj += sk;
                sk = 0;
            }
            if(sj < 0) return 0;
            mint res = s2[sj][sk];
            if(tj >= 0 && tk <= d){
                res -= s2[tj][tk];
            }
            return res;
        };
        rep(j, 0, d+1) rep(k, 0, d+1){
            mint now;
            now += sum1(j-1, k-w-1);
            now += sum1(j-w-1, k-1);
            now += sum2(j, k-w, w);
            dp[j][k] = now;
        }
    }
    
    mint ans = 0;
    rep(j, 0, d+1) rep(k, 0, d+1){
        ans += dp[j][k];
    }
    cout << ans.val() << endl;

    return 0;
}