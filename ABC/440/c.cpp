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

int main(){
    int t; cin >> t;
    while(t--){
        ll n, w; cin >> n >> w;
        vector<ll> c(n);
        vector<ll> sum_c(2*w);
        rep(i, 0, n){
            cin >> c[i];
            sum_c[i%(2*w)] += c[i];
        }

        ll tmp = 0;
        rep(i, 0, n){
            if(i%(2*w) < w) tmp += c[i];
        }
        ll ans = tmp;
        rep(x, 1, 2*w){
            tmp -= sum_c[x-1];
            tmp += sum_c[(x-1+w)%(2*w)];
            chmin(ans, tmp);
        }
        cout << ans << endl;


    }
    return 0;
}