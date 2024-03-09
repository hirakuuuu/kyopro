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
// https://atcoder.jp/contests/abc344/tasks/abc344_c

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    int m; cin >> m;
    vector<ll> b(m);
    rep(i, 0, m) cin >> b[i];
    int l; cin >> l;
    vector<ll> c(l);
    rep(i, 0, l) cin >> c[i];
    map<ll, bool> able;
    rep(i, 0, n){
        rep(j, 0, m){
            rep(k, 0, l){
                able[a[i]+b[j]+c[k]] = true;
            }
        }
    }

    int q; cin >> q;
    while(q--){
        ll x; cin >> x;
        if(able[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}