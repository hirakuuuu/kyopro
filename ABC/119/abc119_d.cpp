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
// https://atcoder.jp/contests/abc119/tasks/abc119_d

int main(){
    ll a, b, q; cin >> a >> b >> q;
    vector<ll> s(a+2), t(b+2);
    s[0] = t[0] = -INF;
    rep(i, 1, a+1) cin >> s[i];
    rep(i, 1, b+1) cin >> t[i];
    s[a+1] = t[b+1] = INF;

    while(q--){
        ll x; cin >> x;
        int ps = lower_bound(s.begin(), s.end(), x)-s.begin();
        int pt = lower_bound(t.begin(), t.end(), x)-t.begin();
        
        ll ans = INF;
        rep(i, ps-1, ps+1){
            rep(j, pt-1, pt+1){
                chmin(ans, min(abs(s[i]-x), abs(t[j]-x))+abs(s[i]-t[j]));
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}