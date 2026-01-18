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
    int n, q; cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, 0, n){
        cin >> b[i];
    }
    ll sum = 0;
    rep(i, 0, n){
        sum += min(a[i], b[i]);
    }


    while(q--){
        char c; cin >> c;
        int x, v; cin >> x >> v;
        x--;
        if(c == 'A'){
            sum -= min(a[x], b[x]);
            a[x] = v;
            sum += min(a[x], b[x]);
        }else{
            sum -= min(a[x], b[x]);
            b[x] = v;
            sum += min(a[x], b[x]);
        }
        cout << sum << endl;
    }
    
    return 0;
}