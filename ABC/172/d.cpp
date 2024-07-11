#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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

// 0ならば素数, 0でないなら最小の素因数
vector<ll> erat(10000005);
void init_e(){
    rep(i, 2, sqrt(10000005)){
        if(erat[i] == 0){
            for(ll j = i*i; j < 10000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}


int main(){
    init_e();
    ll n; cin >> n;
    ll ans = 0;
    rep(k, 1, n+1){
        ll f = 1, tmp = k;
        while(erat[tmp] != 0){
            ll cnt = 0, p = erat[tmp];
            while(tmp%p == 0){ cnt++; tmp /= p; }
            f *= cnt+1;
        }
        if(tmp != 1) f *= 2;
        ans += f*k;
    }
    cout << ans << endl;
    
    return 0;
}