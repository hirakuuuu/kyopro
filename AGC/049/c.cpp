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
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    stack<pair<ll, int>> stc;
    rep(i, 0, n){
        if(a[i] > b[i]){
            ll l = a[i]-b[i];
            while(!stc.empty() && stc.top().first >= l) stc.pop();
        }else{
            stc.push({a[i], i});
        }
    }

    vector<int> p(n);
    ll cnt = 0;
    while(!stc.empty()){
        p[stc.top().second] = 1; stc.pop();
        cnt++;
    }
    ll ans = cnt;
    rep(i, 0, n){
        if(a[i] > b[i]) continue;
        cnt -= p[i];
        chmin(ans, max(cnt, b[i]-a[i]+1));
    }
    cout << ans << endl;

    return 0;
}