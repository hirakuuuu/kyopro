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
    int n, q; cin >> n >> q;

    // start -> goal の移動で pivot に相方がいる状態での最小操作回数
    auto g = [&](int start, int goal, int pivot) -> ll {
        ll res = INF;
        if(start > goal) swap(start, goal);
        if(inr(start, pivot, goal)) chmin(res, (start-goal+n)%n);
        else chmin(res, (goal-start)%n);
        return res;
    };
    // sl -> gl, sr -> gr と移動するときの最小操作回数
    auto f = [&](int sl, int gl, int sr, int gr) -> ll {
        if(sl == sr || gl == gr){
            // この状態は達成できない
            return INF;
        }

        ll res = INF;
        // r を固定して, l を動かし, その後 l を固定して, r を動かす
        if(gl != sr) chmin(res, g(sl, gl, sr)+g(sr, gr, gl));

        // l を固定して, r を動かし, その後 r を固定して, l を動かす
        if(gr != sl) chmin(res, g(sr, gr, sl)+g(sl, gl, gr));
        return res;
    };

    vector<ll> ldp(n, INF), rdp(n, INF); // l, r の位置は固定されていて、もう一方が i の場合の最小値
    char pre_h = '?';
    int pre_t = -1;
    // 1つめの指示は分けて処理
    {
        q--;
        char h; cin >> h;
        int t; cin >> t; t--;
        if(h == 'L'){
            rep(i, 0, n){
                ldp[i] = f(0, t, 1, i);
            }
        }else{
            rep(i, 0, n){
                rdp[i] = f(0, i, 1, t);
            }
        }
        pre_h = h;
        pre_t = t;
    }
    
    while(q--){
        char h; cin >> h;
        int t; cin >> t; t--;
        if(h == 'L'){
            if(pre_h == 'L'){
                vector<ll> pre_ldp = ldp;
                ldp = rdp = vector<ll>(n, INF);
                rep(i, 0, n){
                    // もう一方を動かさない
                    chmin(ldp[i], pre_ldp[i]+f(pre_t, t, i, i)); 
                    // 動かすなら, t+1 or t-1 にいる状態だけ考えればよい
                    chmin(ldp[(t+1)%n], pre_ldp[i]+f(pre_t, t, i, (t+1)%n));
                    chmin(ldp[(t-1+n)%n], pre_ldp[i]+f(pre_t, t, i, (t-1+n)%n));
                }
            }else{
                vector<ll> pre_rdp = rdp;
                ldp = rdp = vector<ll>(n, INF);
                rep(i, 0, n){
                    // もう一方を動かさない
                    chmin(ldp[pre_t], pre_rdp[i]+f(i, t, pre_t, pre_t));
                    // 動かすなら, t+1 or t-1 にいる状態だけ考えればよい
                    chmin(ldp[(t+1)%n], pre_rdp[i]+f(i, t, pre_t, (t+1)%n));
                    chmin(ldp[(t-1+n)%n], pre_rdp[i]+f(i, t, pre_t, (t-1+n)%n));
                }
            }
        }else{
            if(pre_h == 'L'){
                vector<ll> pre_ldp = ldp;
                ldp = rdp = vector<ll>(n, INF);
                rep(i, 0, n){
                    // もう一方を動かさない
                    chmin(rdp[pre_t], pre_ldp[i]+f(pre_t, pre_t, i, t));
                    // 動かすなら, t+1 or t-1 にいる状態だけ考えればよい
                    chmin(rdp[(t+1)%n], pre_ldp[i]+f(pre_t, (t+1)%n, i, t));
                    chmin(rdp[(t-1+n)%n], pre_ldp[i]+f(pre_t, (t-1+n)%n, i, t));
                }
            }else{
                vector<ll> pre_rdp = rdp;
                ldp = rdp = vector<ll>(n, INF);
                rep(i, 0, n){
                    // もう一方を動かさない
                    chmin(rdp[i], pre_rdp[i]+f(i, i, pre_t, t));
                    // 動かすなら, t+1 or t-1 にいる状態だけ考えればよい
                    chmin(rdp[(t+1)%n], pre_rdp[i]+f(i, (t+1)%n, pre_t, t));
                    chmin(rdp[(t-1+n)%n], pre_rdp[i]+f(i, (t-1+n)%n, pre_t, t));
                }
            }
        }
        pre_h = h;
        pre_t = t;
    }

    ll ans = INF;
    if(pre_h == 'L'){
        rep(i, 0, n){
            chmin(ans, ldp[i]);
        }
    }else{
        rep(i, 0, n){
            chmin(ans, rdp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}