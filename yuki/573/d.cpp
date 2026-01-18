#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

ll mod_pow(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

pair<ll, ll> exeuclid(ll a, ll b) {
  if(b == 0) {
    return make_pair(1, 0);
  }
  else {
    auto [x,y] = exeuclid(b, a%b);
    return make_pair(y, -(a/b) * y + x);
  }
}

int modinv(ll x, ll m) {
  auto [i,p] = exeuclid(x, m);
  return i < 0 ? i + m : i;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll x, m; cin >> x >> m;
        string sx = to_string(x);
        int n = (int)sx.size();
        
        ll ans = -1;
        rep(i, 1, n+1){
            bool f = true;
            rep(j, 0, i){
                if(sx[(n-i)+j] != sx[j]) f = false;
            }
            if(f){
                ll num = x;
                int ten = 1;
                rep(j, 0, n) ten *= 10;
                rrep(j, n-1-i, 0) num += ten*(sx[j]-'0'), ten *= 10;
                if(num%m == 0) ans = num;
            }
        }

        ll ten = 1;
        rep(_, 0, n) ten *= 10;
        ll ten_ = ten;
        ll g = gcd(m, ten_);
        ll a = ten_/g;
        ll b = m/g;
        ll ep = modinv(a, b);

        rep(i, 2*n, 19){
            if(ans != -1) break;
            ll k = x+x*ten;
            ll tmp = ((-k)%m+m)%m;
            // cout << i-2*n << ' ' << tmp << endl;
            if(m == g){
                if(tmp == 0) ans = k;
            }else if(tmp%g == 0){

                tmp /= g;
                // x \equiv tmp*mod_pow(a, b-2);
                ll y = (tmp*ep)%b;
                // cout << (mod_pow(a, euler_phi(b)-1, b)*a)%b << endl;
                // assert((mod_pow(a, euler_phi(b)-1, b)*a)%b == 1);
                // cout << i-2*n << ' ' << y << endl;
                if(y == 0 || to_string(y).size() <= i-2*n){
                    ans = k+y*ten_;
                }
            }
            ten *= 10;

        }
        assert(ans == -1 || ans%m == 0);
        cout << ans << endl;
    }

    return 0;
}