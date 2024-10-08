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
    ll k; cin >> k;
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    sx += 2*k, sy += 2*k, tx += 2*k, ty += 2*k; // 4近傍にずらしても負の値が出ないように
    auto is_in_small = [&](ll i, ll j) -> bool { return !(((i/k)+(j/k))&1); };

    auto calc_nearest_big = [&](ll si, ll sj, int d) -> tuple<ll, ll, ll> {
        if(!is_in_small(si, sj)) return {si, sj, 0};

        ll cost = 0;
        if(d == 0){
            // 左　si -> k で割ったあまりが 0 になるようにする
            cost = min({k-(si%k), si%k+1LL+4LL, k-(sj%k)+2LL, sj%k+1LL+2LL});
            si += k-(si%k);
        }else if(d == 1){
            // 右　si -> k で割ったあまりが k-1 になるようにする
            cost = min({k-(si%k)+4LL, si%k+1LL, k-(sj%k)+2LL, sj%k+1LL+2LL});
            si -= (si%k)+1;
        }else if(d == 2){
            // 上　sj -> k で割ったあまりが 0 になるようにする
            cost = min({k-(sj%k), sj%k+1LL+4LL, k-(si%k)+2LL, si%k+1LL+2LL});
            sj += k-(sj%k);
        }else{
            // 下　sj -> k で割ったあまりが k-1 になるようにする
            cost = min({k-(sj%k)+4LL, sj%k+1LL, k-(si%k)+2LL, si%k+1LL+2LL});
            sj -= (sj%k)+1;
        }
        return {si, sj, cost};
    };

    auto calc_big2big = [&](ll si, ll sj, ll ti, ll tj) -> ll {
        assert(!is_in_small(si, sj));
        assert(!is_in_small(ti, tj));
        
        si /= k, sj /= k;
        ti /= k, tj /= k;
        
        ll di = abs(si-ti), dj = abs(sj-tj);
        ll res = min(dj, di)*2LL+((max(di, dj)-min(di, dj))/2)*min(4LL, k+1);
        return res;
    };

    ll ans = INF;
    if(is_in_small(sx, sy) && is_in_small(tx, ty)){
        // マンハッタン距離になる場合を考慮する
        if(sx/k == tx/k && sy/k == ty/k) chmin(ans, abs(sx-tx)+abs(sy-ty));
        // 近傍の大マスに移動するパターンを全探索
        rep(ds, 0, 4){
            rep(dt, 0, 4){
                auto [nsx, nsy, cost_s] = calc_nearest_big(sx, sy, ds);
                auto [ntx, nty, cost_t] = calc_nearest_big(tx, ty, dt);
                chmin(ans, cost_s+calc_big2big(nsx, nsy, ntx, nty)+cost_t);
            }
        } 
    }else if(is_in_small(sx, sy)){
        // {sx, sy} の近傍の大マスに移動するパターンを全探索
        rep(ds, 0, 4){
            auto [nsx, nsy, cost_s] = calc_nearest_big(sx, sy, ds);
            chmin(ans, cost_s+calc_big2big(nsx, nsy, tx, ty));
        } 
    }else if(is_in_small(tx, ty)){
        // {tx, ty} の近傍の大マスに移動するパターンを全探索
        rep(dt, 0, 4){
            auto [ntx, nty, cost_t] = calc_nearest_big(tx, ty, dt);
            chmin(ans, cost_t+calc_big2big(sx, sy, ntx, nty));
        } 
    }else{
        chmin(ans, calc_big2big(sx, sy, tx, ty));
    }
    cout << ans << endl;

    return 0;
}