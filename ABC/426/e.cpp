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
        long double tsx, tsy, tgx, tgy; cin >> tsx >> tsy >> tgx >> tgy;
        long double asx, asy, agx, agy; cin >> asx >> asy >> agx >> agy;

        auto dist = [&](pair<long double, long double> s, pair<long double, long double> g) -> long double {
            return sqrt((s.first-g.first)*(s.first-g.first)+(s.second-g.second)*(s.second-g.second));
        };

        auto calc = [&](long double sx, long double sy, long double gx, long double gy, long double time) -> pair<long double, long double> {
            long double d = dist({sx, sy}, {gx, gy});
            // cout << d << ' ' << time << endl;
            if(d < time) return {gx, gy};

            long double mx = (sx*(d-time)+gx*time)/d;
            long double my = (sy*(d-time)+gy*time)/d;
            return {mx, my};
        };

        // for(long double e = 0.0; e <= 3.0; e += 0.1){
        //     long double d1 = dist(calc(tsx, tsy, tgx, tgy, e), calc(asx, asy, agx, agy, e));
        //     cout << setprecision(20) << e << ": " << d1 << endl;
        // }
        long double ans = 9e18;
        {
            long double l = 0, r = min(dist({tsx, tsy}, {tgx, tgy}), dist({asx, asy}, {agx, agy}));
            while(r-l > 1e-9){
                long double m1 = (l*51.0+r*49.0)/100.0, m2 = (l*49.0+r*51.0)/100.0;
                long double d1 = dist(calc(tsx, tsy, tgx, tgy, m1), calc(asx, asy, agx, agy, m1));
                long double d2 = dist(calc(tsx, tsy, tgx, tgy, m2), calc(asx, asy, agx, agy, m2));
                if(d1 < d2) r = m2;
                else l = m1;
            }
            long double ans_l = dist(calc(tsx, tsy, tgx, tgy, l), calc(asx, asy, agx, agy, l));
            long double ans_r = dist(calc(tsx, tsy, tgx, tgy, r), calc(asx, asy, agx, agy, r));
            chmin(ans, min(ans_l, ans_r));
        }
        {
            long double l = min(dist({tsx, tsy}, {tgx, tgy}), dist({asx, asy}, {agx, agy}));
            long double r = max(dist({tsx, tsy}, {tgx, tgy}), dist({asx, asy}, {agx, agy}));
            while(r-l > 1e-9){
                long double m1 = (l*51.0+r*49.0)/100.0, m2 = (l*49.0+r*51.0)/100.0;
                long double d1 = dist(calc(tsx, tsy, tgx, tgy, m1), calc(asx, asy, agx, agy, m1));
                long double d2 = dist(calc(tsx, tsy, tgx, tgy, m2), calc(asx, asy, agx, agy, m2));
                if(d1 < d2) r = m2;
                else l = m1;
            }
            long double ans_l = dist(calc(tsx, tsy, tgx, tgy, l), calc(asx, asy, agx, agy, l));
            long double ans_r = dist(calc(tsx, tsy, tgx, tgy, r), calc(asx, asy, agx, agy, r));
            chmin(ans, min(ans_l, ans_r));
        }
       
        cout << setprecision(20) << ans << endl;
    }
    
    return 0;
}