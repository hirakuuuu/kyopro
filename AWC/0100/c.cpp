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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, q; cin >> n >> l >> q;
    vector<ll> s(n);
    rep(i, 0, n){
        string t; cin >> t;
        reverse(t.begin(), t.end());
        rep(j, 0, l){
            ll b = (t[j]-'0');
            s[i] += b<<j;
        }
    }

    rep(i, 0, q){
        int m; cin >> m;
        ll ans = 0;
        rep(j, 0, m){
            int c; cin >> c; c--;
            ans |= s[c];
        }
        rep(j, 0, l){
            cout << ((ans>>(l-1-j))&1);
        }
        cout << endl;
    }

    return 0;
}