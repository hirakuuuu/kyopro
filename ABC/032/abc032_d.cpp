#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc032/tasks/abc032_d

ll val[205], wei[205];

int main(){
    ll n, w; cin >> n >> w;
    ll mw = 0;
    rep(i, 1, n+1){
        cin >> val[i] >> wei[i];
        mw = max(mw, wei[i]);
    }
    if(n <= 30){
        // 半分全列挙
        vector<pll> vw;
        rep(i, 0, 1<<15){
            ll total_w = 0;
            ll total_v = 0;
            rep(j, 0, 15){
                if((i&(1<<j)) > 0){
                    total_w += wei[j+1];
                    total_v += val[j+1];
                }
            }
            vw.push_back({total_w, total_v});
        }
        sort(vw.begin(), vw.end());
        vw.erase(unique(vw.begin(), vw.end()), vw.end());
        vector<ll> val_f(vw.size());
        rep(i, 1, vw.size()){
            val_f[i] = max(val_f[i-1], vw[i].second);
        }

        ll ans = 0;

        rep(i, 0, 1<<15){
            ll total_w = 0;
            ll total_v = 0;
            rep(j, 0, 15){
                if((i&(1<<j)) > 0){
                    total_w += wei[16+j];
                    total_v += val[16+j];
                }
            }
            if(total_w <= w){
                int pos = lower_bound(vw.begin(), vw.end(), make_pair(w-total_w+1, 0LL))-vw.begin()-1;
                ans = max(ans, val_f[pos]+total_v);
            }
        }
        cout << ans << endl;
    }else if(mw > 1000){
        // 価値jを達成するために必要な最小重さでdp
        vector<ll> dp(200005, 1LL<<60);
        vector<ll> dp_(200005, 1LL<<60);
        dp_[0] = 0;
        rep(i, 1, n+1){
            rep(j, 0, 200005){
                if(j >= val[i]) dp[j] = min(dp_[j], dp_[j-val[i]]+wei[i]);
                else dp[j] = dp_[j];
            }
            dp_ = dp;
        }
        ll ans = 0;
        rep(i, 0, 200005){
            if(dp[i] <= w) ans = i;
        }
        cout << ans << endl;
    }else{
        // 重さｊで達成できる最大価値でdp
        vector<ll> dp(200005);
        vector<ll> dp_(200005);
        rep(i, 1, n+1){
            rep(j, 1, 200005){
                if(j >= wei[i]) dp[j] = max(dp_[j], dp_[j-wei[i]]+val[i]);
                else dp[j] = dp_[j];
            }
            dp_ = dp;
        }
        cout << dp[min(w, 200000LL)] << endl;
    }
    
    return 0;
}