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
p が 2, 5 でなければ, 10の累乗で割る部分が p の倍数であるかどうかに影響を及ぼさない
よって, p で割ったあまりをメモしておけばよい.
*/

int main(){
    int n, p; cin >> n >> p;
    string s; cin >> s;
    ll ans = 0;
    if(p == 2){
        rep(i, 0, n){
            if((s[i]-'0')%2 == 0) ans += (ll)(i+1);
        }
    }else if(p == 5){
        rep(i, 0, n){
            if((s[i]-'0')%5 == 0) ans += (ll)(i+1);
        }
    }else{
        vector<ll> cnt(p);
        cnt[0]++;
        int tmp = 0, ten = 1;
        rrep(i, n-1, 0){
            tmp = (tmp+ten*(s[i]-'0'))%p;
            ten = (ten*10)%p;
            ans += cnt[tmp];
            cnt[tmp]++;
        }
    }
    cout << ans << endl;


    
    return 0;
}