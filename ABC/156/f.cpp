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
余事象を考えると、商が1増えるタイミングを数えれば良い
初項と末項をそれぞれ求めて、商がいくつ増えるかを計算
*/

int main(){
    int k, q; cin >> k >> q;
    vector<ll> D(k);
    rep(i, 0, k) cin >> D[i];
    while(q--){
        ll n, x, m; cin >> n >> x >> m;
        vector<ll> d(k);
        ll sum = 0;
        rep(i, 0, k){
            d[i] = D[i]%m;
            if(d[i] == 0) d[i] = m;
            sum += d[i];
        }

        n--;
        ll ans = n;
        ll start = x, last = x;
        last += (n/k)*sum;
        rep(i, 0, n%k) last += d[i];
        ans -= (last/m)-(start/m);
        cout << ans << endl;
    }
    
    return 0;
}