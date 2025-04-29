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
    int r, c; cin >> r >> c;
    vector<string> s(r);
    rep(i, 0, r) cin >> s[i];

    vector<ll> cnt_r(r), cnt_c(c);
    rep(i, 0, r){
        rep(j, 0, c){
            if(s[i][j] == '.'){
                cnt_r[i]++;
                cnt_c[j]++;
            }
        }
    }

    vector<ll> mul_r(r), mul_c(c);
    rep(i, 0, r){
        ll tot = 0;
        rep(j, 0, c){
            if(s[i][j] == '.'){
                tot += cnt_c[j]-1;
            }
        }
        tot *= tot;
        rep(j, 0, c){
            if(s[i][j] == '.'){
                tot -= (cnt_c[j]-1)*(cnt_c[j]-1);
            }
        }
        mul_r[i] = tot;
    }
    rep(i, 0, c){
        ll tot = 0;
        rep(j, 0, r){
            if(s[j][i] == '.'){
                tot += cnt_r[j]-1;
            }
        }
        tot *= tot;
        rep(j, 0, r){
            if(s[j][i] == '.'){
                tot -= (cnt_r[j]-1)*(cnt_r[j]-1);
            }
        }
        mul_c[i] = tot;
    }


    ll ans = 0;
    // i 行目に 2 と 3 がいる場合
    rep(i, 0, r){
        // すべて i 行目から取る
        if(cnt_r[i] >= 4) ans += cnt_r[i]*(cnt_r[i]-1)*(cnt_r[i]-2)*(cnt_r[i]-3);
        // 1->2->3 が i 行目 3->4 が列
        // 1->2 が 列 2->3->4 が i 行目
        if(cnt_r[i] >= 3){
            rep(j, 0, c){
                if(s[i][j] == '.'){
                    ans += 2*(cnt_r[i]-1)*(cnt_r[i]-2)*1*(cnt_c[j]-1);
                }
            }
        }

        // 1->2 と 3->4 が列，2->3 が行
        if(cnt_r[i] >= 2) ans += mul_r[i];
    }
    // i 列目に 2 と 3 がいる場合
    rep(i, 0, c){
        // すべて i 列目から取る
        if(cnt_c[i] >= 4) ans += cnt_c[i]*(cnt_c[i]-1)*(cnt_c[i]-2)*(cnt_c[i]-3);
        
        // 1->2->3 が i 列目 3->4 が行
        // 1->2 が 行 2->3->4 が i 列目
        if(cnt_c[i] >= 3){
            rep(j, 0, r){
                if(s[j][i] == '.'){
                    ans += 2*(cnt_c[i]-1)*(cnt_c[i]-2)*1*(cnt_r[j]-1);
                }
            }
        }

        // 1->2 と 3->4 が列，2->3 が行
        if(cnt_c[i] >= 2) ans += mul_c[i];
    }

    cout << ans << endl;
    return 0;
}