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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool err = false;
    // pre-pos を通る回数を求める（pos = root では０が返ってくるはず）
    auto f = [&](auto self, int pos, int pre) -> ll {

        int cnt = 0;
        ll sum_c = 0, max_c = 0;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            cnt++;
            ll tmp = self(self, nxt, pos);
            sum_c += tmp;
            chmax(max_c, tmp);
        }

        if(cnt == 0){
            return a[pos];
        }

        if(sum_c < a[pos] || a[pos] < max_c || a[pos]*2 < sum_c){
            err = true;
            return 0;
        }
        return a[pos]*2-sum_c;
    };

    if(n == 2){
        if(a[0] == a[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }else{
        rep(i, 0, n){
            if(g[i].size() != 1){
                if(f(f, i, -1) == 0 && !err) cout << "YES" << endl;
                else cout << "NO" << endl;
                break;
            }
        }
    }


    
    return 0;
}