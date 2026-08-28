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
    ll h, w; cin >> h >> w;
    int n; cin >> n;
    vector<ll> a(n), b(n);
    map<ll, ll> l, r;
    map<ll, vector<ll>> bb;
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        if(!l.count(a[i])) l[a[i]] = b[i];
        else chmin(l[a[i]], b[i]);
        if(!r.count(a[i])) r[a[i]] = b[i];
        else chmax(r[a[i]], b[i]);
        bb[a[i]].push_back(b[i]);
    }

    ll ans = INF;
    // 1回も横切らない場合    
    {
        ll tmp = 0;
        for(auto [key, _]: l){
            tmp += r[key]*2;
        }
        ans = tmp;
    }
    // 2回横切る場合
    {
        vector<ll> d;
        for(auto &[key, val]: bb){
            sort(val.begin(), val.end());
            ll mx = 0;
            rep(j, 0, (int)val.size()-1){
                chmax(mx, val[j+1]-val[j]);
            }
            if(val.size() == 1){
                d.push_back(min(val[0], w-1-val[0])*2);
            }else{
                d.push_back(min({(w-1-mx), val.back(), (w-1-val[0])})*2);
            }
        }
        if(d.size() > 1){
            sort(d.begin(), d.end());
            int m = d.size();
            vector<ll> acc(m+1);
            rep(i, 0, m) acc[i+1] += acc[i]+d[i];
            ll tmp = INF;
            ll cnt = (w-1)*2;
            for(int i = m-2; i >= 0; i -= 2){
                chmin(tmp, (acc[i]-acc[0])+cnt);
                cnt += (w-1)*2;
            }
            chmin(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}