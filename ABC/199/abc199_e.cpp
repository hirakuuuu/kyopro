#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc199/tasks/abc199_e

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pii>> cod(n+1);
    rep(i, 0, m){
        int x, y, z; cin >> x >> y >> z;
        cod[x].push_back({y, z});
    }

    vector<ll> dp(1<<n, 0LL);
    dp[0] = 1;

    rep(i, 0, 1<<n){
        vector<int> cnt(n+1);
        rep(j, 1, n+1){
            cnt[j] = cnt[j-1]+((i&(1<<(j-1))) > 0);
        }
        rep(j, 0, n){
            if((i&(1<<j)) == 0){
                bool f = true;
                for(auto yz: cod[cnt[n]+1]){
                    int y = yz.first, z = yz.second;
                    if(cnt[y]+(j+1 <= y) > z) f = false;
                }
                if(f) dp[i+(1<<j)] += dp[i];
            }
        }
    }

    // rep(i, 0, 1<<n){
    //     cout << dp[i] << endl;
    // }

    cout << dp[(1<<n)-1] << endl;


    
    return 0;
}