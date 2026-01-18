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
    int T; cin >> T;
    while(T--){
        ll n, k, x; cin >> n >> k >> x;
        vector<__int128_t> a(n);
        __int128_t t = 1;
        rep(_, 0, 40) t *= 2;
        rep(i, 0, n){
            ll _a; cin >> _a;
            a[i] = _a;
            a[i] *= t;
        }

        __int128_t ok = 0, ng = 1;
        rep(_, 0, 50) ng *= 2;

        while(ng-ok > 1){
            __int128_t mid = (ok+ng)/2;
            __int128_t cnt = 0, tot = 0;
            rep(i, 0, n){
                if(a[i] < mid){
                    tot++;
                    continue;
                }
                __int128_t num = 1;
                __int128_t tmp = mid*2;
                while(a[i] >= tmp){
                    num *= 2;
                    tmp *= 2;
                }
                cnt += num;
                tot += num;
            }
            
            if(cnt >= x && (cnt-x)+tot >= n+k){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        long double ans = ok;
        ans /= (long double)t;
        cout << setprecision(20) << ans << endl;
    }
    return 0;
}