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

ll solve(ll x){
    if(x < 10) return 0;
    vector<int> o;
    ll r_ = x;
    while(r_){
        o.push_back(r_%10);
        r_ /= 10;
    }
    
    int m = (int)o.size();
    ll ans_r = 0;
    // 桁数が m 未満なら適当に足す
    rep(i, 2, m){
        rep(j, 1, 10){
            ll add = 1;
            rep(_, 0, i-1) add *= j;
            ans_r += add;
        }
    }
    // 桁数が m の場合，最上位桁が o[m-1] 未満ならなんでもいい
    rep(j, 1, o[m-1]){
        ll add = 1;
        rep(_, 0, m-1) add *= j;
        ans_r += add;
    }

    // m 桁で最上位桁が o[m-1] の場合，
    // 残りのけたは 0 ~ o[m-1]-1 で埋める
    // ただし r の最上位桁を除いた値以下になるようにする
    vector<ll> dp(o[m-1]);
    ll eq = 1;
    rrep(i, m-2, 0){
        vector<ll> ndp(o[m-1]);
        rep(j, 0, o[m-1]){
            rep(k, 0, o[m-1]) ndp[j] += dp[k];
            if(j < o[i]) ndp[j] += eq;
        }
        if(o[i] >= o[m-1]) eq = 0;
        swap(dp, ndp);
    }
    rep(i, 0, o[m-1]){
        ans_r += dp[i];
    }
    ans_r += eq;
    return ans_r;
}

int main(){
    ll l, r; cin >> l >> r;
    cout << solve(r)-solve(l-1) << endl;
    // int cnt=  0;
    // rep(j, 10, 211){
    //     string s = to_string(j);
    //     bool ok = true;
    //     rep(i, 1, s.size()){
    //         if(s[0] <= s[i]) ok = false;
    //     }
    //     if(ok) cnt++;
    // }
    // cout << cnt << endl;
    // // r 以下のヘビ数の個数を求める
    // {
       
    // }
    
    return 0;
}