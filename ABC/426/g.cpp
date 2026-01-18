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
    vector<ll> w(n), v(n);
    rep(i, 0, n){
        cin >> w[i] >> v[i];
    }
    int q; cin >> q;
    vector<tuple<int, int, int, int>> query(q);
    vector<int> l(q), r(q), c(q);
    rep(i, 0, q){
        cin >> l[i] >> r[i] >> c[i]; l[i]--;
    }

    vector<ll> ans(q);
    vector<vector<ll>> dp(n+1, vector<ll>(501));
    auto f = [&](auto self, int nl, int nr, vector<int> &qid) -> void {
        if(nl+1 == nr){
            for(int id: qid){
                if(w[l[id]] <= c[id]) ans[id] = v[l[id]];
            }
            return;
        }


        int m = (nl+nr)/2;
        rep(i, 0, 501) dp[m][i] = 0;
        rrep(i, m-1, nl){
            rep(j, 0, 501){
                dp[i][j] = dp[i+1][j];
                if(w[i] <= j) chmax(dp[i][j], dp[i+1][j-w[i]]+v[i]);
            }
        }
        rep(i, m+1, nr+1){
            rep(j, 0, 501){
                dp[i][j] = dp[i-1][j];
                if(w[i-1] <= j) chmax(dp[i][j], dp[i-1][j-w[i-1]]+v[i-1]);
            }
        }

        vector<int> qid_l, qid_r;
        for(auto id: qid){
            if(r[id] <= m){
                qid_l.push_back(id);
            }else if(m <= l[id]){
                qid_r.push_back(id);
            }else{
                rep(i, 0, c[id]+1){
                    chmax(ans[id], dp[l[id]][i]+dp[r[id]][c[id]-i]);
                }
            }
        }
        self(self, nl, m, qid_l);
        self(self, m, nr, qid_r);
        return;
    };

    vector<int> qid(q);
    iota(qid.begin(), qid.end(), 0);
    f(f, 0, n, qid);

    rep(i, 0, q){
        cout << ans[i] << endl;
    }

    return 0;
}