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
    
    int n; cin >> n;
    long double s, t; cin >> s >> t;
    vector<long double> a(n), b(n), c(n), d(n);
    rep(i, 0, n) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    auto dist = [&](long double sx, long double sy, long double tx, long double ty) -> long double {
        return sqrt((sx-tx)*(sx-tx)+(sy-ty)*(sy-ty));
    };

    auto solve = [&]() -> long double {
        long double sx = 0, sy = 0;
        long double res = 0;
        rep(i, 0, n){
            // (sx, sy) -> (a[p[i]], b[p[i]])
            res += dist(sx, sy, a[p[i]], b[p[i]])/s;
            // (a[p[i]], b[p[i]]) -> (c[p[i]], d[p[i]])
            res += dist(a[p[i]], b[p[i]], c[p[i]], d[p[i]])/t;

            sx = c[p[i]], sy = d[p[i]];
        }
        return res;
    };

    long double ans = 9e18;
    do{
        rep(i, 0, 1<<n){
            rep(j, 0, n){
                if((i>>j)&1){
                    swap(a[p[j]], c[p[j]]);
                    swap(b[p[j]], d[p[j]]);
                }
            }
            chmin(ans, solve());
            rep(j, 0, n){
                if((i>>j)&1){
                    swap(a[p[j]], c[p[j]]);
                    swap(b[p[j]], d[p[j]]);
                }
            }
        }
    }while(next_permutation(p.begin(), p.end()));
    cout << setprecision(20) << ans << endl;
    return 0;
}