#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc317/tasks/abc317_f

int main(){
    ll n; cin >> n; 
    vector<ll> a(3);
    rep(i, 0, 3) cin >> a[i];
    ll o = 1, cnt = 0;
    while(o < n){
        o *= 2;
        cnt++;
    }

    vector<vector<ll>> amari(3, vector<ll>(cnt));
    rep(i, 0, 3){
        ll p = 1;
        rep(j, 0, cnt){
            amari[i][j] = p;
            p *= 2;
            p %= a[i];
        }
    }

    ll ans = 0;

    vector<vector<vector<vector<ll>>>> dp(a[0], vector<vector<vector<ll>>>(a[1], vector<vector<ll>>(a[2], vector<ll>(8))));
    dp[0][0][0][0] = 1;
    rrep(i, cnt-1, 0){
        vector<vector<vector<vector<ll>>>> dp_(a[0], vector<vector<vector<ll>>>(a[1], vector<vector<ll>>(a[2], vector<ll>(8))));
        rep(ii, 0, 2){
            rep(jj, 0, 2){
                rep(kk, 0, 2){
                    if((ii+jj+kk)%2) continue;
                    rep(i_, 0, a[0]){
                        rep(j_, 0, a[1]){
                            rep(k_, 0, a[2]){
                                if((n&(1LL<<i)) > 0){
                                    rep(j, 0, 8){
                                        dp_[(i_+ii*amari[0][i])%a[0]][(j_+jj*amari[1][i])%a[1]][(k_+kk*amari[2][i])%a[2]][j] += dp[i_][j_][k_][j];
                                    }
                                }else{
                                    rep(j, 0, 8){
                                        
                                        dp_[(i_+ii*amari[0][i])%a[0]][(j_+jj*amari[1][i])%a[1]][(k_+kk*amari[2][i])%a[2]][j] += dp[i_][j_][k_][j];
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
        dp = dp_;
    }

    cout << dp[0][0][0] << endl;
    
    

    
    return 0;
}