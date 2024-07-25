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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

mint dp[65][10][11][11][11];


int main(){
    ll n; cin >> n; 
    vector<ll> a(3);
    rep(i, 0, 3) cin >> a[i];

    dp[60][7][0][0][0] = 1;
    rrep(i, 59, 0){
        // dp の方の遷移
        if((n>>i)&1){
            rep(e, 0, 8){
                rep(j, 0, a[0]) rep(k, 0, a[1]) rep(l, 0, a[2]){
                    rep(nj, 0, 2) rep(nk, 0, 2) rep(nl, 0, 2){
                        if((nj+nk+nl)&1) continue;
                        int ne = 0;
                        if(((e>>2)&1) && nj) ne += 1<<2;
                        if(((e>>1)&1) && nk) ne += 1<<1;
                        if((e&1) && nl) ne += 1;
                        dp[i][ne][(2*j+nj)%a[0]][(2*k+nk)%a[1]][(2*l+nl)%a[2]] += dp[i+1][e][j][k][l];
                    }
                }
            }
        }else{
            rep(e, 0, 8){
                rep(j, 0, a[0]) rep(k, 0, a[1]) rep(l, 0, a[2]){
                    rep(nj, 0, 2) rep(nk, 0, 2) rep(nl, 0, 2){
                        if((nj+nk+nl)&1) continue;
                        if(((e>>2)&1) && nj) continue;
                        if(((e>>1)&1) && nk) continue;
                        if((e&1) && nl) continue;
                        dp[i][e][(2*j+nj)%a[0]][(2*k+nk)%a[1]][(2*l+nl)%a[2]] += dp[i+1][e][j][k][l];
                    }
                }
            }
        }
    }

    mint ans = 0;
    rep(i, 0, 8){
        ans += dp[0][i][0][0][0];
    }
    // 0の場合を除く
    ans -= 1; // 全部 0 
    rep(i, 0, 3) ans -= n/lcm(a[i], a[(i+1)%3]); // 1つ 0
    cout << ans.val() << endl;


    
    return 0;
}