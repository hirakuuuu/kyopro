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

/*
半分全列挙
*/


int main(){
    ll n, k, p; cin >> n >> k >> p;
    vector<ll> a(40);
    rep(i, 0, n) cin >> a[i];
    vector<vector<ll>> dp(41);
    rep(i, 0, 1<<20){
        bool f = true;
        int cnt = 0;
        rep(j, 0, 20){
            if((i>>j)&1){
                cnt++;
                if(a[j] == 0) f = false;
            }
        }
        if(!f) continue;
        ll sum = 0;
        rep(j, 0, 20){
            if((i>>j)&1) sum += a[j];
        }
        dp[cnt].push_back(sum);
    }
    rep(i, 0, 20) sort(dp[i].begin(), dp[i].end());
    ll ans = 0;
    rep(i, 0, 1<<20){
        bool f = true;
        int cnt = 0;
        rep(j, 0, 20){
            if((i>>j)&1){
                cnt++;
                if(a[j+20] == 0) f = false;
            }
        }
        if(!f || k-cnt < 0) continue;
        ll sum = 0;
        rep(j, 0, 20){
            if((i>>j)&1) sum += a[j+20];
        }
        ans += upper_bound(dp[k-cnt].begin(), dp[k-cnt].end(), p-sum)-dp[k-cnt].begin();
    }
    cout << ans << endl;


    return 0;
}