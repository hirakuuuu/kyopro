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

/*
拡張ユークリッドの互除法 : 
    ax+by=gcd(a, b)を満たす(x, y)を求めるアルゴリズム。
    (a, b) に関する問題を (b, a%b) に関する問題に帰着することで再帰的に解く。
*/

// 返り値: a と b の最大公約数
// ax+by=gcd(a, b) を満たす (x, y) が格納される
// 返り値の絶対値が欲しいときは必ずabsをつけましょう

ll extGCD(ll a, ll b, ll &x, ll &y){
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

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
ll ceil2(ll y, ll x){
    if(y%x == 0){
        return y/x;
    }
    return floor2(y, x)+1;
}

int main(){
    ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    ll ans = 0;
    ll g = gcd(b, c);
    for(ll i = 1; i <= n; i++){
        ll z = d-a*i;
        if(z <= 0) break;
        if(z%g != 0) continue;
        ll B = b/g, C = c/g, Z = z/g;
        ll x, y;
        g = extGCD(B, C, x, y);
        x *= Z;
        y *= Z;
        // cout << x << ' ' << y << endl;
        // Zj := x-c*t, Zk := y+b*t;
        ll l1, r1, l2, r2;
        l1 = ceil2(x-n*Z, C);
        r1 = ceil2(x-Z+1, C);
        if(l1 >= r1) continue;
        l2 = ceil2(Z-y, B);
        r2 = ceil2(Z*n+1-y, B);
        if(l2 >= r2) continue;

        cout << x << ' ' << y << endl;about:blank#blocked
        cout << i << ": " << l1 << ", " << r1 << ", " << l2 << ", " << r2 << endl;

        ll l = max({Z*l1, Z*l2, Z-1});
        ll r = min({Z*r1, Z*r2, Z*n+1});
        cout << i << ": " << l << ", " << r << endl;
        ans += max(0LL, r-l);        
    }
    cout << ans << endl;
    
    return 0;
}