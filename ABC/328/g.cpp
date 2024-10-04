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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n;
    ll c; cin >> n >> c;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<ll> dp(1<<n, INF);
    dp[0] = -c;

    rep(i, 0, 1<<n){
        rep(l, 0, n){
            if(!((i>>l)&1)){
                ll cost = c, cnt = __popcount(i);
                rep(r, l, n){
                    if((i>>r)&1) break;
                    cost += abs(a[r]-b[cnt]);
                    cnt++;
                    // 連続して含まれていないやつについて、遷移させるみたいな感じにすると O(nn2^n) → O(n2^n) に落ちる
                    chmin(dp[i+(((1<<r+1)-1)^((1<<l)-1))], dp[i]+cost);
                }
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
    
    
    return 0;
}