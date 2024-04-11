#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<long double> c(n), p(n);
    vector<vector<int>> s(n);
    vector<long double> cnt_zero(n);
    rep(i, 0, n){
        int P; cin >> c[i] >> P;
        s[i].resize(P);
        p[i] = (long double)P;
        rep(j, 0, p[i]){
            cin >> s[i][j];
            if(s[i][j] == 0) cnt_zero[i] += 1.0;
        }
    }
    vector<long double> dp(2*m, 9e18);
    rep(i, m, 2*m) dp[i] = 0.0;
    rrep(i, m-1, 0){
        rep(j, 0, n){
            long double tmp = 0.0, sum = 0.0;
            for(auto ss: s[j]){
                if(ss == 0) continue;
                sum += dp[i+ss];
            }
            tmp = (c[j]*p[j]+sum)/(p[j]-cnt_zero[j]);
            chmin(dp[i], tmp);
        }
    }
    cout << setprecision(20) << dp[0] << endl;
}