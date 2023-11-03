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
// https://atcoder.jp/contests/abc236/tasks/abc236_e

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    double l = 0.0, r = 1e9;
    while(r-l > 1e-5){
        double m = (r+l)/2.0;
        vector<double> b(n);
        rep(i, 0, n) b[i] = (double)a[i]-m;
        vector<vector<double>> dp(n+1, vector<double>(2));
        rep(i, 0, n){
            dp[i+1][0] = dp[i][1];
            dp[i+1][1] = max(dp[i][0], dp[i][1])+b[i];
        }
        double tmp = max(dp[n][0], dp[n][1]);
        if(tmp >= 0.0) l = m;
        else r = m;
    }
    printf("%.10f\n", l);

    set<int> s, t;
    s.insert(0);
    s.insert(n+1);
    t.insert(0);
    t.insert(-n-1);
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 1);
    sort(ind.begin(), ind.end(), [&](int i, int j){
        return a[i-1] > a[j-1];
    });

    int rest = n/2;
    rep(j, 0, n){
        int i = ind[j];
        int li = -(*t.lower_bound(-i));
        int ri = *s.lower_bound(i);

        rest -= (ri-li-1)/2;
        rest += (i-li-1)/2;
        rest += (ri-i-1)/2;
        s.insert(i);
        t.insert(-i);
        if(j < rest) continue;
        cout << a[i-1] << endl;
        break;
    }
    return 0;
}