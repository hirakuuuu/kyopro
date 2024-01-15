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
// https://atcoder.jp/contests/abc336/tasks/abc336_e


int main(){
    ll n; cin >> n;
    ll o = 0, m = n;
    vector<ll> c;
    while(m){
        c.push_back(m%10);
        m /= 10;
        o++;
    }
    reverse(c.begin(), c.end());
    vector dp(2, vector<vector<vector<ll>>>(150, vector<vector<ll>>(150, vector<ll>(150))));
    rep(i, 1, 150){
        dp[0][0][i][0] = 1;
    }
    rep(i, 0, o){
        vector dp_(2, vector<vector<vector<ll>>>(150, vector<vector<ll>>(150, vector<ll>(150))));
        rep(j, 0, 150){
            rep(k, 0, 10){
                if(j+k >= 150) continue;
                rep(ii, 1, 150){
                    rep(jj, 0, ii){
                        if(c[i] == k) dp_[0][j+k][ii][(jj*10+k)%ii] += dp[0][j][ii][jj];
                        if(c[i] > k) dp_[1][j+k][ii][(jj*10+k)%ii] += dp[0][j][ii][jj];
                        dp_[1][j+k][ii][(jj*10+k)%ii] += dp[1][j][ii][jj];
                    }
                }
            }
        }
        swap(dp_, dp);
    }

    ll ans = 0;
    rep(i, 1, 150){
        ans += dp[0][i][i][0]+dp[1][i][i][0];
    }
    cout << ans << endl;


    
    return 0;
}