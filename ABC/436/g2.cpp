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
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// bostan_mori algorithm
// p(x)/q(x) の x^m の係数を O(|p+q|\log{|p+q|}\log{m}) 時間で求める
// q(-x) をかけることで奇数項を消せるので，これを高々 log{m} 回繰り返せば終わる
mint bostan_mori(vector<mint> p, vector<mint> q, ll n){
    while(n){
        vector<mint> iq = q;
        for(int i = 1; i < q.size(); i += 2) iq[i] = -iq[i];
        p = convolution(p, iq);
        iq = convolution(q, iq);
        for(int i = 0; i < q.size(); i++) q[i] = iq[i*2];
        for(int i = n&1; i < p.size(); i += 2) p[i/2] = p[i];
        p.resize((p.size()+!(n&1))/2);
        n >>= 1;
    }
    return p[0]/q[0];
}

int main(){
    int n; cin >> n;
    ll m; cin >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<mint> p = {1};
    vector<mint> q = {1, -1};
    rep(i, 0, n){
        vector<mint> r(a[i]+1);
        r[0] = 1, r[a[i]] = -1;
        q = convolution(q, r);
    }

    cout << bostan_mori(p, q, m).val() << endl;


    return 0;
}