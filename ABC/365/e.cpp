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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 0;
    rep(i, 0, 30){
        vector<int> b(n);
        rep(j, 0, n) b[j] = ((a[j]>>i)&1);
        
        ll tmp = 0;
        vector<ll> cnt(2);
        cnt[0] = 1;
        int acc = 0, sum = 0;
        rep(j, 0, n){
            acc ^= b[j];
            tmp += cnt[1-acc];
            cnt[acc]++;
            sum += b[j];
        }
        ans += (tmp-sum)*(1LL<<i);
    }
    cout << ans << endl;


    return 0;
}