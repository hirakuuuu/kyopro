#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> acc_l(n), acc_r(n);
    acc_l[0] = a[0], acc_r[n-1] = a[n-1];
    rep(i, 1, n) acc_l[i] = acc_l[i-1]^a[i];
    rrep(i, n-2, 0) acc_r[i] = acc_r[i+1]^a[i];

    if(acc_l[n-1] > 0){
        int tot = acc_l[n-1];
        int acc = 0;
        vector<mint> dp(n);
        vector<mint> sum(1<<20);
        sum[0] = 1;
        rep(i, 0, n){
            acc ^= a[i];
            dp[i] += sum[acc^tot];
            sum[acc] += dp[i];
            // cout << dp[i].val() << endl;
        }
        cout << dp[n-1].val() << endl;
        return 0;
    }

    vector<int> cnt(n+1);
    rep(i, 1, n+1){
        cnt[i] = cnt[i-1];
        if(acc_l[i-1] == 0) cnt[i]++;
    }

    vector<vector<int>> t(1<<20);
    rep(i, 0, n-1){
        if(acc_l[i] == acc_r[i+1]) t[acc_l[i]].push_back(i);
    }
    
    mint ans = 0;
    ans += mint(2).pow(t[0].size());
    rep(i, 1, 1<<20){
        if(t[i].size() == 0) continue;
        mint sum = 0, del = 0, zero = 0, sum_tmp = 0;
        int pre = 0;
        rep(j, 0, (int)t[i].size()){
            mint tmp = (sum-del)+1;
            ans += tmp;
            sum_tmp += tmp;
            if(j == (int)t[i].size()-1) break;

            pre = t[i][j];
            int cur = cnt[t[i][j+1]]-cnt[pre];
            del += tmp*zero;
            zero += cur;
            sum = sum_tmp*zero;
        }
    }
    cout << ans.val() << endl;

    
    return 0;
}