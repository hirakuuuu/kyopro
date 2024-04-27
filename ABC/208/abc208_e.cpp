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
各桁の数字の積として現れうる数は, 0 or 2^{i}3^{j}5^{k}7^{l};
それぞれの指数を持って桁DP
全部足したものをｎから引けば、0になる場合も求まる

vectorにしようとしたけど添え字がめんどくさいので、mapに変更（出てくる数字が少ないので、これでも十分早い）

*/


int main(){
    ll n, K; cin >> n >> K;
    int o = 0;
    ll n_ = n;
    while(n_){
        o++; n_ /= 10;
    }
    unordered_map<ll, ll> cnt;
    string s = to_string(n);
    ll tmp = (ll)(s[0]-'0');
    rep(i, 1, tmp) cnt[(ll)i]++;
    rep(i, 1, o){
        unordered_map<ll, ll> cnt_;
        for(auto [key, val]: cnt){
            rep(j, 0, 10){
                cnt_[key*j] += val;
            }
        }
        rep(j, 1, 10){
            cnt_[j]++;
        }
        rep(j, 0, s[i]-'0'){
            cnt_[tmp*j]++;
        }
        tmp *= (ll)(s[i]-'0');
        swap(cnt, cnt_);
    }
    cnt[tmp]++;
    ll ans = 0;
    for(auto [key, val]: cnt){
        // cout << key << ' ' << val << endl;
        if(key <= K) ans += val;
    }
    cout << ans << endl;

    
    return 0;
}