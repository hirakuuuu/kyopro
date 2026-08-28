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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int q; cin >> q;
    vector<ll> x(2*n), y(2*n);
    vector<ll> ax(2*n+1), ay(2*n+1); // x[i]*x[i]*y[i+1], y[i]*x[i]*y[i+1];
    vector<ll> bx(2*n+1), by(2*n+1); // x[i]*x[i+1]*y[i], y[i]*x[i+1]*y[i];
    vector<ll> cx(2*n+1), cy(2*n+1); // x[i+1]*x[i]*y[i+1], y[i+1]*x[i]*y[i+1];
    vector<ll> dx(2*n+1), dy(2*n+1); // x[i+1]*x[i+1]*y[i], y[i+1]*x[i+1]*y[i];
    vector<ll> e(2*n+1); // x[i]*y[i+1]-x[i+1]*y[i];
    rep(i, 0, n) cin >> x[i] >> y[i];
    rep(i, 0, n) x[i+n] = x[i], y[i+n] = y[i];

    rep(i, 1, 2*n+1){
        int j = (i-1)%n, k = (j+1)%n;

        // x[i]*x[i]*y[i+1], y[i]*x[i]*y[i+1];
        ax[i] = ax[i-1]+x[j]*x[j]*y[k];
        ay[i] = ay[i-1]+y[j]*x[j]*y[k];

        // x[i]*x[i+1]*y[i], y[i]*x[i+1]*y[i];
        bx[i] = bx[i-1]+x[j]*x[k]*y[j];
        by[i] = by[i-1]+y[j]*x[k]*y[j];

        // x[i+1]*x[i]*y[i+1], y[i+1]*x[i]*y[i+1];
        cx[i] = cx[i-1]+x[k]*x[j]*y[k];
        cy[i] = cy[i-1]+y[k]*x[j]*y[k];

         // x[i+1]*x[i+1]*y[i], y[i+1]*x[i+1]*y[i];
        dx[i] = dx[i-1]+x[k]*x[k]*y[j];
        dy[i] = dy[i-1]+y[k]*x[k]*y[j];

        // x[i]*y[i+1]-x[i+1]*y[i];
        e[i] = e[i-1]+(x[j]*y[k]-x[k]*y[j]);
    }


    rep(i, 0, q){
        int u, v; cin >> u >> v; u--, v--;
        if(u < v){
            // [u, v];
            ll X = 0;
            {
                X += (ax[v]-ax[u])+(x[v]*x[v]*y[u]);
                X -= (bx[v]-bx[u])+(x[v]*x[u]*y[v]);
                X += (cx[v]-cx[u])+(x[u]*x[v]*y[u]);
                X -= (dx[v]-dx[u])+(x[u]*x[u]*y[v]);
            }
            ll Y = 0;
            {
                Y += (ay[v]-ay[u])+(y[v]*x[v]*y[u]);
                Y -= (by[v]-by[u])+(y[v]*x[u]*y[v]);
                Y += (cy[v]-cy[u])+(y[u]*x[v]*y[u]);
                Y -= (dy[v]-dy[u])+(y[u]*x[u]*y[v]);
            }
            cout << setprecision(20) << (ld)X/(((e[v]-e[u])+(x[v]*y[u]-x[u]*y[v]))*3) << ' ' << (ld)Y/(((e[v]-e[u])+(x[v]*y[u]-x[u]*y[v]))*3) << endl;
        }else{
            // [v, u+n];
            v += n;
            // cout << u << ' ' << v << endl;
            ll X = 0;
            {
                X += (ax[v]-ax[u])+(x[v]*x[v]*y[u]);
                X -= (bx[v]-bx[u])+(x[v]*x[u]*y[v]);
                X += (cx[v]-cx[u])+(x[u]*x[v]*y[u]);
                X -= (dx[v]-dx[u])+(x[u]*x[u]*y[v]);
            }
            ll Y = 0;
            {
                Y += (ay[v]-ay[u])+(y[v]*x[v]*y[u]);
                Y -= (by[v]-by[u])+(y[v]*x[u]*y[v]);
                Y += (cy[v]-cy[u])+(y[u]*x[v]*y[u]);
                Y -= (dy[v]-dy[u])+(y[u]*x[u]*y[v]);
            }
            cout << setprecision(20) << (ld)X/(((e[v]-e[u])+(x[v]*y[u]-x[u]*y[v]))*3) << ' ' << (ld)Y/(((e[v]-e[u])+(x[v]*y[u]-x[u]*y[v]))*3) << endl;
        }
    }
    
    return 0;
}