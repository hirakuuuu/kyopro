#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> d(n);
    rep(i, 0, n) cin >> d[i];
    vector<ll> acc_l(n+1), acc_r(n+1);
    rep(i, 0, n) acc_l[i+1] = acc_l[i]+d[i];
    rrep(i, n-1, 0) acc_r[i] = acc_r[i+1]+d[i];
    sort(acc_r.begin(), acc_r.end());
    ll ans = 0;
    rep(i, 1, n+1){
        ll a = acc_l[i];
        int pos = lower_bound(acc_r.begin(), acc_r.end(), a) - acc_r.begin();
        if(acc_r[pos] == a && i-1 < n-pos) chmax(ans, a);
    }
    cout << ans << endl;
    return 0;
}