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





int main(){
    int n; cin >> n;
    vector<int> p(n);
    vector<vector<int>> g(n);
    rep(i, 1, n){
        cin >> p[i]; p[i]--;
        g[p[i]].push_back(i);
    }

    vector<ll> c(n), d(n);
    rep(i, 0, n){
        int C; cin >> C;
        c[i] = C;
    }
    rep(i, 0, n){
        int D; cin >> D; 
        d[i] = D;
    }

    bool ng = false;
    vector<ll> cnt_c(n), cnt_d(n);
    auto f = [&](auto self, int pos, int pre) -> void {
        cnt_c[pos] += c[pos];
        cnt_d[pos] += d[pos];
        for(auto nxt: g[pos]){
            self(self, nxt, pos);
            cnt_c[pos] += cnt_c[nxt];
            cnt_d[pos] += cnt_d[nxt];
        }
        if(cnt_c[pos] < cnt_d[pos]){
            ng = true;
        }
        return;
    };
    f(f, 0, -1);
    if(ng){
        cout << 0 << endl;
        return 0;
    }

    auto f2 = [&](auto self, int pos, int pre) -> mint {
        ll tot = c[pos];
        mint res = 1;
        for(auto nxt: g[pos]){
            mint now = self(self, nxt, pos);
            res *= now;
            tot += cnt_c[nxt]-cnt_d[nxt];
        }
        if(tot < d[pos]){
            return 0;
        }
        // cout << pos << ' ' << tot << ' ' << res.val() << endl;

        for(ll k = tot; k >= tot-d[pos]+1; k--){
            res *= k;
        }
        for(ll k = d[pos]; k >= 1; k--){
            res /= k;
        }
        // cout << pos << ' ' << tot << ' ' << res.val() << endl;
        return res;
    };
    cout << f2(f2, 0, -1).val() << endl;

    
    return 0;
}