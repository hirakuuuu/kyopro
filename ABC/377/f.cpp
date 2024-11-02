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
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m);
    rep(i, 0, m) cin >> a[i] >> b[i];

    vector<ll> r = a, c = b;
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    ll ans = n*n;
    // 縦、横の移動でとられるマスを調べる
    {
        ans -= n*r.size();
        ans -= n*c.size();
        ans += r.size()*c.size();
    }
    // 斜めでとられるマスを調べる
    {   
        set<ll> s; // 和を管理
        set<ll> t; // 差を管理
        rep(i, 0, m){
            // 和
            if(s.find(a[i]+b[i]) == s.end()){
                if(a[i]+b[i]-1 <= n) ans -= a[i]+b[i]-1;
                else ans -= 2*n-(a[i]+b[i]-1);

                set<pair<ll, ll>> seen;
                // 横でカウントされてる分
                for(auto rr: r){
                    if(inr(1, a[i]+b[i]-rr, n+1)) seen.insert({rr, a[i]+b[i]-rr});
                }
                // 縦でカウントされてる分
                for(auto cc: c){
                    if(inr(1, a[i]+b[i]-cc, n+1)) seen.insert({a[i]+b[i]-cc, cc});
                }
                // 差でカウントされてる分
                for(auto tt: t){
                    if((a[i]+b[i]+tt)%2 == 0 && (a[i]+b[i]-tt)%2 == 0){
                        ll ci = (a[i]+b[i]+tt)/2, cj = (a[i]+b[i]-tt)/2;
                        if(inr(1, ci, n+1) && inr(1, cj, n+1)) seen.insert({ci, cj});
                    }
                }
                ans += (ll)seen.size();
                s.insert(a[i]+b[i]);
            }

            // 差
            if(t.find(a[i]-b[i]) == t.end()){
                if(-(a[i]-b[i]-1) >= 1) ans -= n+1+(a[i]-b[i]-1);
                else ans -= n-1-(a[i]-b[i]-1);

                set<pair<ll, ll>> seen;
                // 横でカウントされてる分
                for(auto rr: r){
                    if(inr(1, -(a[i]-b[i]-rr), n+1)) seen.insert({rr, -(a[i]-b[i]-rr)});
                }
                // 縦でカウントされてる分
                for(auto cc: c){
                    if(inr(1, a[i]-b[i]+cc, n+1)) seen.insert({a[i]-b[i]+cc, cc});
                }
                // 和でカウントされてる分
                for(auto ss: s){
                    if((a[i]-b[i]+ss)%2 == 0 && (ss-a[i]+b[i])%2 == 0){
                        ll ci = (a[i]-b[i]+ss)/2, cj = (ss-a[i]+b[i])/2;
                        if(inr(1, ci, n+1) && inr(1, cj, n+1)) seen.insert({ci, cj});
                    }
                }
                ans += (ll)seen.size();
                t.insert(a[i]-b[i]);
            }
        }
    }    
    cout << ans << endl;
    
    return 0;
}