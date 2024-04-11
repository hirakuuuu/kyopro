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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> l(n+1), r(n+1);
    rep(i, 0, n) cin >> l[i] >> r[i];
    sort(l.rbegin(), l.rend());
    sort(r.begin(), r.end());
    ll ans = 0, acc = 0;
    rep(i, 0, n){
        acc += (l[i]-r[i])*2;
        chmax(ans, acc);
    }
    cout << ans << endl;
    return 0;
}