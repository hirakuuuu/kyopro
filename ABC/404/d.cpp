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
    int n, m; cin >> n >> m;
    vector<ll> c(n);
    rep(i, 0, n) cin >> c[i];

    vector<vector<int>> cnt;
    vector<int> t;
    auto f = [&](auto self, int pos) -> void {
        if(pos == n){
            cnt.push_back(t);
            return;
        }
        rep(i, 0, 3){
            t.push_back(i);
            self(self, pos+1);
            t.pop_back();
        }
    };
    f(f, 0);

    rep(i, 0, m){
        int k; cin >> k;
        vector<int> ok(n);
        rep(_, 0, k){
            int a; cin >> a; a--;
            ok[a] = 1;
        }
        vector<vector<int>> new_cnt;

        for(auto cc: cnt){
            int tmp = 0;
            rep(j, 0, n){
                tmp += ok[j]*cc[j];
            }
            if(tmp >= 2) new_cnt.push_back(cc);
        }
        swap(cnt, new_cnt);
    }

    ll ans = INF;
    for(auto cc: cnt){
        ll tmp = 0;
        rep(i, 0, n){
            tmp += c[i]*cc[i];
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}