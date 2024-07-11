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
    ll n, t; cin >> n >> t;
    string s; cin >> s;
    vector<ll> x(n), l, r;
    rep(i, 0, n){
        cin >> x[i];
        if(s[i] == '0') l.push_back(x[i]);
        else r.push_back(x[i]);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    
    ll ans = 0;
    rep(i, 0, n){
        if(s[i] == '0'){
            ans += upper_bound(r.begin(), r.end(), x[i])-lower_bound(r.begin(), r.end(), x[i]-2*t);
        }else{
            ans += upper_bound(l.begin(), l.end(), x[i]+2*t)-lower_bound(l.begin(), l.end(), x[i]);
        }
    }
    cout << ans/2 << endl;

    
    return 0;
}