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
    int n, m; cin >> n >> m;
    vector<vector<ll>> A(n, vector<ll>(m));
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> A[i][j];
        }
    }
    vector<vector<ll>> acc(n+1, vector<ll>(m+1));
    rep(i, 0, n){
        rep(j, 0, m){
            acc[i+1][j+1] = acc[i][j+1]+acc[i+1][j]-acc[i][j]+A[i][j];
        }
    }
    auto sum = [&](int lx, int ly, int rx, int ry) -> ll {
        return acc[rx][ry]-acc[rx][ly]-acc[lx][ry]+acc[lx][ly];
    };


    auto max_area_histogram = [&](vector<int> h, int d, int mi) -> ll {
        h.push_back(0);
        stack<pair<int, int>> dot;
        ll res = 0;
        // (x座標, 高さ)
        rep(i, 0, h.size()){
            int nx = i;
            while(!dot.empty() && dot.top().second >= h[i]){
                auto [cx, cy] = dot.top(); dot.pop();
                // cout << cx << ' ' << i <<' ' << d-cy << ' ' << d << ' ' << sum(d-cy, cx,  d, i) << endl;
                chmax(res, (ll)sum(d-cy, cx,  d, i)*mi);
                nx = cx;
            }
            dot.push({nx, h[i]});
        }
        return res;
    };  

    ll ans = 0;
    rrep(mi, 300, 1){
        vector<int> h(m);
        rep(i, 0, n){
            rep(j, 0, m){
                if(A[i][j] >= mi) h[j]++;
                else h[j] = 0;
            }
            chmax(ans, max_area_histogram(h, i+1, mi));
        }
    }
    cout << ans << endl;
    return 0;
}