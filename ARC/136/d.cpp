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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    // 高速ゼータ変換の応用
    vector<ll> dp(1000005);
    rep(i, 0, n) dp[a[i]]++;
    rep(i, 0, 7){
        int ten = 1;
        rep(_, 0, i) ten *= 10;
        rep(x, 0, 1000000){
            if((x%(ten*10)) >= ten){
                dp[x] += dp[x-ten];
            }
        }
    }
    ll ans = 0;
    rep(i, 0, n){
        ans += dp[999999-a[i]];
        bool self = true;
        int ai = a[i];
        while(ai){
            if(ai%10 >= 5) self = false;
            ai /= 10;
        }
        if(self) ans--;
    }
    cout << ans/2 << endl;
    return 0;
}