#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_j

double dp[305][305][305];

int main(){
    int n; cin >> n;
    vector<int> a(n), cnt(4);
    rep(i, 0, n){
        cin >> a[i];
        cnt[a[i]]++;
    }

    rep(i, 0, n+1){
        rep(j, 0, n+1){
            if(i+j > n) break;
            rep(k, 0, n+1){
                if(i+j+k > n) break;
                double cnt_0 = n-(i+j+k);
                double e = 0;
                // 0貫の皿を引く回数の期待値
                if(cnt_0 < n) e += cnt_0/(n-cnt_0)+1;

                // 3貫の皿を引いた後の期待値
                if(i > 0) e += (double) dp[i-1][j+1][k]*i/(i+j+k);
                // 2貫の皿を引いた後の期待値
                if(j > 0) e += (double) dp[i][j-1][k+1]*j/(i+j+k);
                // 1貫の皿を引いた後の期待値
                if(k > 0) e += (double) dp[i][j][k-1]*k/(i+j+k);
                
                dp[i][j][k] = e;
            }
        }
    }

    printf("%.10f\n", dp[cnt[3]][cnt[2]][cnt[1]]);

    
    
    return 0;
}