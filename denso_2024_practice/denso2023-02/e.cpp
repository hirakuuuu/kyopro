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
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    
    unordered_map<int, int> cnt1, cnt2, cnt3, cnt4;
    rep(i, 0, n){
        cnt1[x[i]]++;
        cnt2[y[i]]++;
        cnt3[x[i]-y[i]]++;
        cnt4[x[i]+y[i]]++;
    }

    ll ans = (ll)n*(n-1);
    for(auto [_, val]: cnt1){
        ans -= (ll)val*(val-1)/2;
    }
    for(auto [_, val]: cnt2){
        ans -= (ll)val*(val-1)/2;
    }
    for(auto [_, val]: cnt3){
        ans -= (ll)val*(val-1)/2;
    }
    for(auto [_, val]: cnt4){
        ans -= (ll)val*(val-1)/2;
    }
    cout << ans << endl;
    return 0;
}