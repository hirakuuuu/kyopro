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
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


// 繰り返し二乗法
ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}


int main(){

    // ll a, b; cin >> a >> b;
    // if(a > b) swap(a, b);
    // map<pair<int, int>, bool> seen;
    // int cnt = 0;
    // while(a != b && !seen[{a, b}]){
    //     cout << cnt << ": " << a << ", " << b << endl;
    //     seen[{a, b}] = true;
    //     b -= a;
    //     a += a;
    //     if(a > b) swap(a, b);
    //     cnt++;
    // }
    // cout << cnt << ": " << a << ", " << b << endl;
    // cout << "count: " << cnt << endl;


    int T; cin >> T;
    while(T--){
        ll a, b; cin >> a >> b;
        if(a > b) swap(a, b);

        auto f = [&](auto self, ll a, ll b, int cnt) -> int {
            if(a == 0) return cnt;
            if((a+b)%2 == 1) return -1;
            ll g = gcd(a, b);
            a /= g, b /= g;
            b -= a;
            a += a;
            if(a > b) swap(a, b);
            return self(self, a, b, cnt+1);
        };

        int cnt = f(f, a, b, 0);
        if(cnt == -1){
            cout << 2 << endl;
        }else{
            ll ans = 2;
            ans -= power(power(2, cnt-1), MOD-2);
            if(ans < 0) ans += MOD;
            cout << ans << endl;
        }

    }
    
    return 0;
}