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
    int n, m, k; cin >> n >> m >> k;
    vector<string> s(n);
    rep(i, 0, n){
        cin >> s[i];
    }

    vector<vector<ll>> cnt_le_k(n+1, vector<ll>(m+1));
    rep(i, 1, n+1) rep(j, 1, m+1){
        cnt_le_k[i][j] = cnt_le_k[i-1][j]+min(k/i, j);
    }
    // rep(i, 1, n+1) rep(j, 1, m+1){
    //     cout << i << ' ' << j << ' ' << cnt_le_k[i][j] << endl;
    // }

    vector<vector<int>> obs_v(n);
    vector<vector<int>> obs_h(m);
    rep(i, 0, n) rep(j, 0, m){
        if(s[i][j] == '#'){
            obs_v[i].push_back(j);
            obs_h[j].push_back(i);
        }
    }
    rep(i, 0, n){
        obs_v[i].push_back(m);
    }
    rep(j, 0, m){
        obs_h[j].push_back(n);
    }

    vector<vector<ll>> acc(n+1, vector<ll>(m+1));
    rep(i, 0, n) rep(j, 0, m){
        acc[i+1][j+1] = acc[i+1][j]+acc[i][j+1]-acc[i][j]+(s[i][j] == '#');
    }

    // [sx, tx) x [sy, ty) 
    auto sum = [&](int sx, int sy, int tx, int ty) -> ll {
        return acc[tx][ty]-acc[sx][ty]-acc[tx][sy]+acc[sx][sy];
    };

    ll ans = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            if(s[i][j] == '#') continue;
            int lx = i, ly = j;
            int rx = *upper_bound(obs_h[j].begin(), obs_h[j].end(), i);
            int ry = *upper_bound(obs_v[i].begin(), obs_v[i].end(), j);

            int mx, my;
            {
                int ok = lx, ng = rx+1;
                while(ng-ok > 1){
                    int mid = (ok+ng)/2;
                    if(sum(lx, ly, mid, ry) == 0) ok = mid;
                    else ng = mid;
                }
                mx = ok;
            }
            {
                int ok = ly, ng = ry+1;
                while(ng-ok > 1){
                    int mid = (ok+ng)/2;
                    if(sum(lx, ly, rx, mid) == 0) ok = mid;
                    else ng = mid;
                }
                my = ok;
            }
            cout << lx << ' ' << ly << ' ' << rx << ' ' << ry << ' ' << mx << ' ' << my << endl;
            cout << rx-lx << ' ' << my-ly << ", " << mx-lx << ' ' << ry-ly << ", " << mx-lx << ' ' << ry-ly << endl;
            cout << cnt_le_k[rx-lx][my-ly] << ' ' << cnt_le_k[mx-lx][ry-ly] << ' ' << cnt_le_k[mx-lx][my-ly] << endl;
            ll tmp = cnt_le_k[rx-lx][my-ly]+cnt_le_k[mx-lx][ry-ly]-cnt_le_k[mx-lx][my-ly];
            ans += tmp;
            // cout << i << ' ' << j << ' ' << tmp << endl;
        }
    }
    cout << ans << endl;


    
    return 0;
}