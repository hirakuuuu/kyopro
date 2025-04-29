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

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}


// MOD と互いに素なら逆元が必ず存在，拡張ユークリッドで求まる
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



int main(){
    int t; cin >> t;
    while(t--){
        ll MOD = 1e9;
        ll n, m; cin >> n >> m;
        n %= MOD, m %= MOD;
        if(n == 0){
            if(m == 0) cout << 1 << endl;
            else cout << -1 << endl;
            continue;
        }
        if(m == 0){
            cout << MOD << endl;
            continue;
        }
        ll g = gcd(n, MOD);
        if(m%g != 0){
            cout << -1 << endl;
            continue;
        }
        // 互いに素にしないと逆元は求まらない
        n /= g, m /= g, MOD /= g;
        ll x, y;
        g = extGCD(n, MOD, x, y);
        x %= MOD;
        if(x < 0) x += MOD;
        ll ans = ((MOD-m)*x)%MOD;
        cout << ans << endl;
    }
    return 0;
}