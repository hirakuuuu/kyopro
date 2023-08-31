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
// https://atcoder.jp/contests/dp/tasks/dp_u

int main(){
    int n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }

    vector<ll> dp(1<<n);
    vector<int> bit(n);
    rep(i, 1, 1<<n){
        rep(j, 0, n){
            if((i&(1<<j)) > 0) bit[j] = 1;
            else bit[j] = 0;
        }

        rep(j, 0, n){
            rep(k, j+1, n){
                if(bit[j] && bit[k]){
                    dp[i] += a[j][k];
                }
            }
        }

        for(int j = i; j >= 0; j--){
            j &= i;
            chmax(dp[i], dp[j]+dp[j^i]);
        }
    }

    cout << dp[(1<<n)-1] << endl;
    
    return 0;
}