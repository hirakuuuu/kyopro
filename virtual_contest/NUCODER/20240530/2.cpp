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
    int n, m, q; cin >> n >> m >> q;
    vector<int> w(n), v(n);
    rep(i, 0, n) cin >> w[i] >> v[i];
    vector<int> x(m);
    rep(i, 0, m) cin >> x[i];

    while(q--){
        int l, r; cin >> l >> r;
        l--;
        vector<int> x_;
        rep(i, 0, m){
            if(inr(l, i, r)) continue;
            x_.push_back(x[i]);
        }
        sort(x_.begin(), x_.end());
        vector<int> used(n);
        ll ans = 0;
        rep(i, 0, x_.size()){
            int ind = -1;
            ll tmp_v = 0;
            rep(j, 0, n){
                if(used[j]) continue;
                if(w[j] <= x_[i] && tmp_v < v[j]){
                    ind = j;
                    tmp_v = v[j];
                }
            }
            if(ind == -1) continue;
            used[ind] = 1;
            ans += tmp_v;
        }
        cout << ans << endl;
    }
    
    return 0;
}