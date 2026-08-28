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

// reference: https://trap.jp/post/2905/
// 有理数 y/x の floor を求める 
ll floor2(ll y, ll x){
    if((x^y) > 0){
        // 同符号の場合，そのまま
        x = abs(x), y = abs(y);
        return y/x;
    }else if((x^y) < 0){
        // 異符号の場合
        // 正の整数 x, y について，floor(-y/x) = -ceil(y/x);
        x = abs(x), y = abs(y);
        return -((y+x-1)/x); 
    }
    return y/x;
}

// \sum_{i=0}^{n} \lfloor\frac{ci+d}{b}\rfloor を求める.
// floor_sum 関数に 4 つの整数 n, b, c, d をこの順で渡す．
// 正常に動作することが保証される範囲は、n <= 10^9, -10^9<= b, c, d <=10^9, b!=0．
ll internal_floor_sum(ll a, ll b, ll c){
    if(c < 0) return 0;
    if(a > b) return internal_floor_sum(b, a, c);
    if(b%a == 0){
        return (1+floor2(c, a))*(1+floor2(c, b))-(b/a)*floor2(c, b)*(floor2(c, b)+1)/2;
    }
    ll k = floor2(c-b*floor2(c, b), a);
    return (1+k)*(1+floor2(c, b)) 
           + floor2(b, a)*floor2(c, b)*(floor2(c, b)+1)/2 
           + internal_floor_sum(a, b%a, c-a*(floor2(b, a)*floor2(c, b)+k+1));
}

// verify: https://atcoder.jp/contests/abc443/tasks/abc443_g
ll floor_sum(ll n, ll b, ll c, ll d){
    if(n < 0) return 0;
    if(b < 0){
        // b を正にする
        b *= -1, c *= -1, d *= -1;
    }
    if(c > 0){
        // c を負にするが，c を -c に置き換えて c > 0 として扱う
        d += n*c;
    }else{
        c *= -1;
    }
    if(c == 0){
        return (n+1)*floor2(d, b);
    }
    ll k = floor2(d-c*n, b);
    return (n+1)*k + internal_floor_sum(b, c, d-b*(k+1));
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n, m, a, b; cin >> n >> m >> a >> b;
        cout << floor_sum(n-1, m, a-1, b+m-1)-floor_sum(n-1, m, a, b) << endl;
    }
    return 0;
}