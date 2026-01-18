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
    vector<int> p(n);
    rep(i, 0, n){
        cin >> p[i];
    }

    vector<int> b, c;
    rep(i, 1, n-1){
        if(p[i-1] < p[i] && p[i] > p[i+1]) b.push_back(i+1);
        if(p[i-1] > p[i] && p[i] < p[i+1]) c.push_back(i+1);
    }
    b.push_back(n), c.push_back(n);
    b.push_back(n), c.push_back(n);

    ll ans = 0;
    rep(l, 0, n-3){
        if(p[l] >= p[l+1]) continue;

        auto b1 = lower_bound(b.begin(), b.end(), l+2);
        auto b2 = b1+1;
        auto c1 = lower_bound(c.begin(), c.end(), l+2);
        auto c2 = c1+1;

        ans += (ll)max(0, min(*b2, *c2)-max(*b1, *c1));
        // cout << *b1 << ' ' << *b2 << endl;
        // cout << *c1 << ' ' << *c2 << endl;
        // cout << ans << endl;
    }
    cout << ans << endl;    
    return 0;
}