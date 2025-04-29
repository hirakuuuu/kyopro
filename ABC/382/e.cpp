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
    int n, x; cin >> n >> x;
    vector<long double> p(n);
    rep(i, 0, n){
        int P; cin >> P;
        p[i] = (long double)P/100.0;
    }

    vector<long double> pr(n+1); // 1パックでレアカードを i 枚手に入れる確率
    vector<long double> acc_pr(n+1);
    {
        pr[0] = 1.0;
        rep(i, 0, n){
            vector<long double> pre = pr;
            rep(j, 0, n+1){
                if(j > 0) pr[j] = pre[j]*(1.0-p[i])+pre[j-1]*p[i];
                else pr[j] = pre[j]*(1.0-p[i]);
            }
        }
        acc_pr[0] = pr[0];
        rep(i, 1, n+1){
            acc_pr[i] = acc_pr[i-1]+pr[i];
        }
    }

    vector<long double> dp(x+1);
    long double zero = 1.0/(1.0-pr[0]);
    // cout << setprecision(20) << zero << endl;
    dp[0] = 0;
    rep(i, 1, x+1){
        rep(j, 1, n+1){
            if(i-j >= x) continue;
            // cout << j << ' ';
            dp[i] += (dp[max(0, i-j)]+zero)*pr[j]*zero;
        }
        // cout << endl;
        // cout << setprecision(20) << dp[i] << endl;
    }
    cout << setprecision(20) << dp[x] << endl;

    // long double ans = 0.0;
    // rep(i, x, x+n) ans += dp[i];
    // cout << setprecision(20) << ans << endl;



    return 0;
}