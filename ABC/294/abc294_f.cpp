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
// https://atcoder.jp/contests/abc294/tasks/abc294_f

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), b(n), c(m), d(m);
    rep(i, 0, n) cin >> a[i] >> b[i];
    rep(i, 0, m) cin >> c[i] >> d[i];

    double ok = 0.0, ng = 1.0;
    while(ng-ok > 1e-15){
        double mid = (ng+ok)/2.0;
        vector<double> taka(n), aoki(m);
        rep(i, 0, n) taka[i] = (double)(1.0-mid)*a[i] - mid*b[i];
        rep(i, 0, m) aoki[i] = (double)(mid-1.0)*c[i] + mid*d[i];

        sort(aoki.begin(), aoki.end());
        ll total = 0;
        rep(i, 0, n){
            int cnt = lower_bound(aoki.begin(), aoki.end(), taka[i]) - aoki.begin();
            total += cnt;
        }

        if(total >= k) ok = mid;
        else ng = mid;
    }

    printf("%.15f\n", 100.0*ok);
    
    return 0;
}