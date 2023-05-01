#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc095/tasks/arc096_b

int main(){
    ll n, c; cin >> n >> c;
    vector<ll> x(n+2), v(n+2);
    rep(i, 1, n+1) cin >> x[i] >> v[i];
    x[n+1] = c;

    vector<ll> csum_r(n+2), csum_l(n+2);
    vector<ll> csum_r2(n+2), csum_l2(n+2);

    vector<vector<ll>> max_sum(4, vector<ll>(n+2));

    rep(i, 0, n){
        csum_r[i+1] = csum_r[i]+v[i+1]-(x[i+1]-x[i]);
        max_sum[0][i+1] = max(max_sum[0][i], csum_r[i+1]);
    }
    rrep(i, n+1, 2){
        csum_l[i-1] = csum_l[i]+v[i-1]-(x[i]-x[i-1]);
        max_sum[1][i-1] = max(max_sum[1][i], csum_l[i-1]);
    }
    rep(i, 0, n){
        csum_r2[i+1] = csum_r2[i]+v[i+1]-2*(x[i+1]-x[i]);
        max_sum[2][i+1] = max(max_sum[2][i], csum_r2[i+1]);
    }
    rrep(i, n+1, 2){
        csum_l2[i-1] = csum_l2[i]+v[i-1]-2*(x[i]-x[i-1]);
        max_sum[3][i-1] = max(max_sum[3][i], csum_l2[i-1]);
    }


    ll ans = 0;
    rep(i, 0, n+1){
        chmax(ans, max_sum[0][i]);
        chmax(ans, max_sum[1][i+1]);
        chmax(ans, max_sum[0][i]+ max_sum[3][i+1]);
        chmax(ans, max_sum[2][i]+ max_sum[1][i+1]);
    }
    cout << ans << endl;

    
    return 0;
}