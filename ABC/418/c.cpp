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
    vector<ll> a(n);
    ll mx = 0;
    rep(i, 0, n){
        cin >> a[i];
        chmax(mx, a[i]);
    }
    sort(a.begin(), a.end());

    vector<ll> acc(n+1);
    rep(i, 0, n){
        acc[i+1] = acc[i]+a[i];
    }

    while(q--){
        ll b; cin >> b;
        if(b > mx){
            cout << -1 << endl;
            continue;
        }

        int cnt = lower_bound(a.begin(), a.end(), b)-a.begin();
        ll ans = acc[cnt]+(b-1)*(n-cnt)+1;
        cout << ans << endl;
    }



    
    return 0;
}