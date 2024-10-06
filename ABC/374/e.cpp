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
    ll X; cin >> X;
    vector<ll> a(n), b(n), p(n), q(n);
    rep(i, 0, n) cin >> a[i] >> p[i] >> b[i] >> q[i];

    // i 番目の機械で s_i を x 台として tot 生成するのに必要なコストの最小値
    auto f = [&](int i, ll x, ll tot) -> ll {
        if(x < 0) return INF;
        // if(x > tot/a[i]) return INF;
        ll res = x*p[i];
        ll y = (max(0LL, tot-x*a[i])+b[i]-1)/b[i];
        res += y*q[i];
        return res;
    };
    // i 番目の機械で t_i を y 台として tot 生成するのに必要なコストの最小値
    auto g = [&](int i, ll y, ll tot) -> ll {
        if(y < 0) return INF;
        // if(x > tot/a[i]) return INF;
        ll res = y*q[i];
        ll x = (max(0LL, tot-y*b[i])+a[i]-1)/a[i];
        res += x*p[i];
        return res;
    };

    ll ok = 0, ng = IINF;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        // 製造能力 mid を予算 x で達成できるか
        ll cost = 0;
        rep(i, 0, n){
            // a[i]*x+b[i]*y >= mid のもとで, p[i]*x+q[i]*y の最小化
            // s[i] を b[i] 個未満 or t[i] を a[i] 個未満としてよい
            // a[i]*b[i] の処理能力はもう一方と交換できるから
            ll tmp = INF;
            rep(x, 0, b[i]){
                chmin(tmp, f(i, x, mid));
            }
            rep(y, 0, a[i]){
                chmin(tmp, g(i, y, mid));
            }
            cost += tmp;
        }
        if(cost <= X) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}