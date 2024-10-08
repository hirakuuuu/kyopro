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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    if(m == 1){
        int cnt = 0;
        rep(i, 0, n) cnt += (a[i]==1);
        cout << (mint(2).pow(cnt)-1).val() << endl;
        return 0; 
    }

    // m の素因数分解
    vector<pair<ll, ll>> pf;
    {
        ll m_ = m;
        for(ll i = 2; i*i <= m_; i++){
            if(m_%i) continue;
            pf.push_back({i, 0});
            while(m_%i == 0){
                pf.back().second++;
                m_ /= i;
            }
        }
        if(m_ != 1) pf.push_back({m_, 1});
    }

    // m の約数だけ残す
    {
        vector<ll> b;
        rep(i, 0, n){
            if(m%a[i] == 0) b.push_back(a[i]);
        }
        swap(a, b);
    }

    // bitに変換
    n = (ll)a.size();
    int k = (int)pf.size();
    vector<int> bit(n);
    rep(i, 0, n){
        rep(j, 0, k){
            auto [p, e] = pf[j];
            bool ok = true;
            rep(_, 0, e){
                if(a[i]%p){ ok = false; break; }
                a[i] /= p;
            }
            if(a[i]%p == 0) ok = false;
            if(ok) bit[i] += (1<<j);
        }
    }

    vector<int> cnt(1<<k);
    rep(i, 0, n) cnt[bit[i]]++;


    vector<mint> dp(1<<k);
    dp[0]++;
    rep(i, 0, 1<<k){
        vector<mint> dp_ = dp;
        mint two = mint(2).pow(cnt[i])-1;
        rep(j, 0, 1<<k){
            dp[(j|i)] += dp_[j]*two;
        }
    }
    cout << dp[(1<<k)-1].val() << endl;

    
    return 0;
}