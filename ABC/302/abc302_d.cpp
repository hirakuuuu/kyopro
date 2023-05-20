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
// https://atcoder.jp/contests/abc302/tasks/abc302_d

int main(){
    ll n, m, d; cin >> n >> m >> d;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = -1;
    rep(i, 0, n){
        auto itr_min = lower_bound(b.begin(), b.end(), a[i]-d);
        auto itr_max = upper_bound(b.begin(), b.end(), a[i]+d);
        if(itr_max != itr_min){
            --itr_max;
            chmax(ans, *itr_max+a[i]);
        }
    }
    cout << ans << endl;
    
    return 0;
}