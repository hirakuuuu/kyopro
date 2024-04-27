#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
二分探索で m 回以上、ok を超える幸福度を得る握手ができる最小の値を求める
後はこれを超える握手の総和を累積和で計算
最終的にｍを超える分のokが余分に足されている可能性があるので、それを調整

*/

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ok = 0, ng = 9e18, cnt = 0;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        ll tmp = 0;
        rep(i, 0, n){
            if(mid-a[i] <= a[i]) tmp++;
            tmp += 2*(a.end()-lower_bound(a.begin()+i+1, a.end(), mid-a[i]));
        }
        if(tmp >= m){
            ok = mid;
            cnt = tmp;
        }else ng = mid;
    }
    // cout<< ok << endl;
    vector<ll> acc(n+1);
    rrep(i, n-1, 0) acc[i] += acc[i+1]+a[i];
    ll ans = 0;
    rep(i, 0, n){
        if(ok-a[i] <= a[i]) ans += a[i]*2;
        int pos = lower_bound(a.begin()+i+1, a.end(), ok-a[i])-a.begin();
        ans += (acc[pos]+(n-pos)*a[i])*2;
    }
    cout << ans-(cnt-m)*ok << endl;
    
    return 0;
}