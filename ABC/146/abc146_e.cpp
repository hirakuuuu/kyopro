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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }
    map<ll, ll> cnt;
    vector<ll> acc(n+1);
    cnt[0] = 1;
    ll ans = 0;
    rep(i, 0, n){
        if(i >= k-1){
            cnt[acc[i-k+1]]--;
        }
        acc[i+1] += a[i]+acc[i];
        acc[i+1] %= k;
        ans += cnt[acc[i+1]];
        cnt[acc[i+1]]++;
    }
    cout << ans << endl;
    
    return 0;
}