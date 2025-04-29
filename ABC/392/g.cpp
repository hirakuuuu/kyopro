#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    int n; cin >> n;
    vector<int> s(n);
    rep(i, 0, n) cin >> s[i];
    sort(s.begin(), s.end());

    vector<ll> a(1000001);
    vector<ll> c(1000001);
    rep(i, 0, n){
        a[s[i]]++;
        c[s[i]]++;
    }
    vector<ll> ac = convolution(a, c);
    rep(i, 0, n){
        ac[s[i]*2]--;
    }

    ll ans = 0;
    rep(i, 1, 2000001){
        if(i%2) continue;
        ans += ac[i]*a[i/2];
    }
    cout << ans/2 << endl;
    
    return 0;
}