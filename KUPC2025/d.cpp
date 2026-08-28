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
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        a[i] += 1e5;
        b[i] += 1e5;
    }

    vector<vector<ll>> gx(200001);
    vector<vector<ll>> gy(200001);
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x += 1e5;
        y += 1e5;
        gx[x].push_back(y);
        gy[y].push_back(x);
    }
    rep(i, 0, 200001){
        sort(gx[i].begin(), gx[i].end());
        sort(gy[i].begin(), gy[i].end());
    }

    auto calc = [&](vector<ll> &p, ll l, ll r) -> vector<ll> {
        bool rev = l > r;
        if(l > r) swap(l, r);
        auto itr_l = lower_bound(p.begin(), p.end(), l);
        auto itr_r = upper_bound(p.begin(), p.end(), r);
        vector<ll> res;
        for(auto itr = itr_l; itr != itr_r; itr++) res.push_back(*itr);
        if(rev) reverse(res.begin(), res.end());
        return res;
    };
    ll d = 0;
    ll mx = 0;
    rep(i, 0, 2*n){
        int from = i%n, to = (i+1)%n;
        if(a[from] == a[to]){
            vector<ll> vec = calc(gx[a[from]], b[from], b[to]);
            ll pre = b[from];
            for(auto v: vec){
                ll tmp = d+abs(pre-v);
                chmax(mx, tmp);
                d = 0;
                pre = v;
            }
            d += abs(b[to]-pre);
        }else{
            vector<ll> vec = calc(gy[b[from]], a[from], a[to]);
            ll pre = a[from];
            for(auto v: vec){
                ll tmp = d+abs(pre-v);
                chmax(mx, tmp);
                d = 0;
                pre = v;
            }
            d += abs(a[to]-pre);
        }
    }

    ll ans = 0;
    rep(i, 0, n) ans += abs(a[i]-a[(i+1)%n])+abs(b[i]-b[(i+1)%n]);
    ans -= mx;
    cout << ans << endl;

    return 0;
}