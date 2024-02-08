#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
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
// https://atcoder.jp/contests/arc170/tasks/arc170_b

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<ll>> pos(11);
    rep(i, 0, n){
        pos[a[i]].push_back(i);
    }
    vector<vector<ll>> r(n, vector<ll>(11, -1));
    rep(i, 0, n){
        rep(j, 1, 11){
            auto itr = upper_bound(pos[j].begin(), pos[j].end(), i);
            if(itr == pos[j].end()) continue;
            r[i][j] = *itr;
        }
    }

    ll ans = 0;
    vector<ll> R(n, INF);
    rep(i, 0, n){
        ll min_r = INF;
        rep(d, -4, 5){
            if(a[i]+2*d < 1 || 10 < a[i]+2*d) continue;
            if(r[i][a[i]+d] == -1 || r[r[i][a[i]+d]][a[i]+2*d] == -1) continue;
            chmin(min_r, r[r[i][a[i]+d]][a[i]+2*d]);
        }
        if(min_r != INF){
            R[i] = min_r;
        }
    }

    ll min_r = INF;
    rrep(i, n-1, 0){
        chmin(min_r, R[i]);
        if(min_r != INF) ans += n-min_r;
    }
    cout << ans << endl;
    
    return 0;
}