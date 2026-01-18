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
    int h, w; cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    ll tot = 0;
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
            tot ^= a[i][j];
        }
    }

    ll ans = tot;
    vector<vector<bool>> b(h, vector<bool>(w));
    auto f = [&](auto self, int pi, int pj) -> void {
        chmax(ans, tot);
        if(pi == h){
            // rep(i, 0, h){
            //     rep(j, 0, w){
            //         if(b[i][j]) cout << '#';
            //         else cout << '.';
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            return;
        }

        if(!b[pi][pj]){
            if(pj < w-1 && !b[pi][pj+1]){
                b[pi][pj] = b[pi][pj+1] = true;
                tot ^= a[pi][pj];
                tot ^= a[pi][pj+1];
                if(pj < w-1) self(self, pi, pj+1);
                else self(self, pi+1, 0);
                b[pi][pj] = b[pi][pj+1] = false;
                tot ^= a[pi][pj];
                tot ^= a[pi][pj+1];
            }

            if(pi < h-1 && !b[pi+1][pj]){
                b[pi][pj] = b[pi+1][pj] = true;
                tot ^= a[pi][pj];
                tot ^= a[pi+1][pj];
                if(pj < w-1) self(self, pi, pj+1);
                else self(self, pi+1, 0);
                b[pi][pj] = b[pi+1][pj] = false;
                tot ^= a[pi][pj];
                tot ^= a[pi+1][pj];
            }
        }

        if(pj < w-1) self(self, pi, pj+1);
        else self(self, pi+1, 0);

        return;
    };

    f(f, 0, 0);
    cout << ans << endl;
    return 0;
}