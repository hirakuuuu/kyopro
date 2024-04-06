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
// https://atcoder.jp/contests/dp/tasks/dp_j

double dp[305][305][305];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> cnt(3);
    rep(i, 0, n) cnt[a[i]-1]++;
    dp[0][0][0] = 0.0;
    rep(i, 0, cnt[2]+1){
        rep(j, 0, cnt[1]+cnt[2]-i+1){
            rep(k, 0, cnt[0]+cnt[1]+cnt[2]-i-j+1){
                if(i+j+k == 0) continue;
                dp[i][j][k] += (double)n/(i+j+k);
                if(i > 0) dp[i][j][k] += (double)i/(i+j+k)*dp[i-1][j+1][k];
                if(j > 0) dp[i][j][k] += (double)j/(i+j+k)*dp[i][j-1][k+1];
                if(k > 0) dp[i][j][k] += (double)k/(i+j+k)*dp[i][j][k-1];
            }
        }
    }
    printf("%.10f\n", dp[cnt[2]][cnt[1]][cnt[0]]);

    

    return 0;
}