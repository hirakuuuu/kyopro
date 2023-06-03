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
// https://atcoder.jp/contests/abc304/tasks/abc304_d

int main(){
    ll w, h; cin >> w >> h;
    int n; cin >> n;
    vector<ll> p(n), q(n);
    rep(i, 0, n) cin >> p[i] >> q[i];

    ll a; cin >> a;
    vector<ll> xa(a+1);
    rep(i, 0, a) cin >> xa[i];
    xa[a] = w;
    ll b; cin >> b;
    vector<ll> yb(b+1);
    rep(i, 0, b) cin >> yb[i];
    yb[b] = h;

    map<pll, ll> cnt;
    set<pll> s;
    rep(i, 0, n){
        ll pos_x = *lower_bound(xa.begin(), xa.end(), p[i]);
        ll pos_y = *lower_bound(yb.begin(), yb.end(), q[i]);
        cnt[{pos_x, pos_y}]++;
        s.insert({pos_x, pos_y});
    }

    ll M = 0, m = n+1;
    for(auto ss: s){
        chmax(M, cnt[ss]);
        chmin(m, cnt[ss]);
    }

    if((a+1)*(b+1) == s.size()){
        cout << m << ' ' << M << endl;
    }else{
        cout << 0 << ' ' << M << endl;
    }




    return 0;
}