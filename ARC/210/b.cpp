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
    int n, m, q; cin >> n >> m >> q;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    multiset<ll> mi, mid, mx;
    vector<ll> ab(n+m);
    rep(i, 0, n) ab[i] = a[i];
    rep(i, 0, m) ab[i+n] = b[i];
    sort(ab.begin(), ab.end());
    ll ans = 0;
    rep(i, 0, n/2) mi.insert(ab[i]), ans += ab[i];
    rep(i, n/2, n+m-n/2) mid.insert(ab[i]);
    rep(i, n+m-n/2, n+m) mx.insert(ab[i]), ans += ab[i];

    while(q--){
        int t, i, x; cin >> t >> i >> x; i--;
        if(t == 1){
            if(mi.find(a[i]) != mi.end()){
                mi.erase(mi.find(a[i]));
                ans -= a[i];
            }else if(mid.find(a[i]) != mid.end()){
                mid.erase(mid.find(a[i]));
            }else{
                mx.erase(mx.find(a[i]));
                ans -= a[i];
            }
            a[i] = x;
            mi.insert(a[i]);
            ans += a[i];
        }else{
            if(mi.find(b[i]) != mi.end()){
                mi.erase(mi.find(b[i]));
                ans -= b[i];
            }else if(mid.find(b[i]) != mid.end()){
                mid.erase(mid.find(b[i]));
            }else{
                mx.erase(mx.find(b[i]));
                ans -= b[i];
            }
            b[i] = x;
            mi.insert(b[i]);
            ans += b[i];
        }
        if(mi.size() > n/2){
            ll tmp = *mi.rbegin();
            mi.erase(mi.find(tmp));
            ans -= tmp;
            mid.insert(tmp);
        }else{
            if(*mi.rbegin() > *mid.begin()){
                ll tmp1 = *mi.rbegin();
                ll tmp2 = *mid.begin();
                mi.erase(mi.find(tmp1));
                ans -= tmp1;
                mid.erase(mid.find(tmp2));
                mi.insert(tmp2);
                ans += tmp2;
                mid.insert(tmp1);
            }
        }

        if(mid.size() > m){
            ll tmp = *mid.rbegin();
            mid.erase(mid.find(tmp));
            mx.insert(tmp);
            ans += tmp;
        }else{
            if(*mid.rbegin() > *mx.begin()){
                ll tmp1 = *mid.rbegin();
                ll tmp2 = *mx.begin();
                mid.erase(mid.find(tmp1));
                mx.erase(mx.find(tmp2));
                ans -= tmp2;
                mid.insert(tmp2);
                mx.insert(tmp1);
                ans += tmp1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}