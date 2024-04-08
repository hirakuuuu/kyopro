#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc346/tasks/abc346_e

int main(){
    ll h, w, m; cin >> h >> w >> m;
    vector<ll> t(m), a(m), x(m);
    rep(i, 0, m){
        cin >> t[i] >> a[i] >> x[i];
        a[i]--;
    }
    vector<ll> ans(200005);
    vector<bool> draw_h(h), draw_w(w);
    ll cnt_h = 0, cnt_w = 0;
    rrep(i, m-1, 0){
        if(t[i] == 1){
            if(draw_h[a[i]]) continue;
            draw_h[a[i]] = true;
            ans[x[i]] += w-cnt_w;
            cnt_h++;
        }else{
            if(draw_w[a[i]]) continue;
            draw_w[a[i]] = true;
            ans[x[i]] += h-cnt_h;
            cnt_w++;
        }
    }
    vector<pair<ll, ll>> area;
    ll total = h*w;
    rep(i, 1, 200005){
        if(ans[i] > 0){
            area.push_back({(ll)i, ans[i]});
            total -= ans[i];
        }
    }
    if(total > 0){
        area.push_back({0, total});
    }
    sort(area.begin(), area.end());
    cout << area.size() << endl;
    for(auto [p, q]: area){
        if(p == 0) q = total;
        cout << p << ' ' << q << endl;
    }
    
    return 0;
}