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

// 問題
// https://atcoder.jp/contests/abc314/tasks/abc314_e

int main(){
    int n, m; cin >> n >> m;
    vector<double> c(n);
    vector<int> p(n);
    vector<vector<int>> s(n);

    rep(i, 0, n){
        cin >> c[i] >> p[i];
        rep(j, 0, p[i]){
            int S; cin >> S;
            if(S) s[i].push_back(S);
        }
        c[i] *= (double)p[i]/s[i].size();
        p[i] = s[i].size();
    }

    vector<double> dp(m+1, 9e18);
    dp[m] = 0.0;
    rrep(i, m-1, 0){
        rep(j, 0, n){
            double sum = 0.0;
            rep(k, 0, p[j]){
                sum += (double)dp[min(m, i+s[j][k])];
            }
            sum /= (double)p[j];
            chmin(dp[i], c[j]+sum);
        }
    }
    printf("%.10f\n", dp[0]);
    return 0;
}