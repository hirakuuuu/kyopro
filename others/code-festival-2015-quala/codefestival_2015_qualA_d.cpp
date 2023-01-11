#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/code-festival-2015-quala/tasks/codefestival_2015_qualA_d

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> x(m+2);
    rep(i, 1, m+1) cin >> x[i];
    x[m+1] = n+1;

    ll ng = -1, ok = 1LL<<60;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        bool flag = true;

        vector<ll> dist(m+1);
        rep(i, 1, m+1){
            // 今いる位置から左にたどり着けなければアウト
            if(x[i]-mid > dist[i-1]+1){
                flag = false;
                break;
            }
            // 時間mid以内で右に移動できる距離の最大値
            ll l = x[i]-dist[i-1]-1;
            ll ok_r = 0, ng_r = n;
            while(ng_r-ok_r > 1){
                ll mid_r = (ok_r+ng_r)/2;
                if(min(2*l+mid_r, l+2*mid_r) <= mid and x[i]+mid_r < x[i+1]) ok_r = mid_r;
                else ng_r = mid_r;
            }

            dist[i] = x[i]+ok_r;
        }
        if(flag and dist[m] == n) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;

    return 0;
}