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

int main(){

    ll n, a; cin >> n >> a;
    vector<ll> w(n), x(n), v(n);
    rep(i, 0, n) cin >> w[i] >> x[i] >> v[i];

    ll ans = 0;
    rep(i, 0, n){
        // i 番目の魚を左端として、右端を全探索する
        vector<ld> tl(n), tr(n);
        rep(j, 0, n){
            if(x[j] < x[i]){
                if(v[j] <= v[i]){ 
                    tl[j] = tr[j] = 9e18; 
                }else{
                    tl[j] = (ld)(x[j]-x[i])/(v[i]-v[j]);
                    tr[j] = tl[j]-(ld)a/(v[i]-v[j]);
                }
            }else{
                if(v[j] == v[i]){
                    if(x[j] <= x[i]+a){ tl[j] = 0.0, tr[j] = 9e18; }
                    else{ tl[j] = tr[j] = 9e18; }
                }else if(v[j] < v[i]){
                    if(x[j] <= x[i]+a) tl[j] = 0.0;
                    else tl[j] = (ld)(x[j]-x[i]-a)/(v[i]-v[j]);

                    tr[j] = (ld)(x[j]-x[i])/(v[i]-v[j]);
                }else{
                    if(x[j] <= x[i]+a){
                        tl[j] = 0.0;
                        tr[j] = (ld)(x[j]-x[i]-a)/(v[i]-v[j]); 
                    }else{
                        tl[j] = tr[j] = 9e18;
                    }
                }
            }
        }

        vector<ld> t = {0.0, 9e18};
        rep(j, 0, n){
            t.push_back(tl[j]);
            t.push_back(tr[j]);
        }
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());

        int m = (int) t.size();
        vector<ll> acc(m);
        rep(j, 0, n){
            int pl = lower_bound(t.begin(), t.end(), tl[j])-t.begin();
            int pr = upper_bound(t.begin(), t.end(), tr[j])-t.begin();
            if(tr[j] == 9e18) pr = m-1;
            acc[pl] += w[j];
            acc[pr] -= w[j];
        }
        rep(j, 0, m-1) acc[j+1] += acc[j];
        rep(j, 0, m) chmax(ans, acc[j]);
    }
    cout << ans << endl;
    
    return 0;
}