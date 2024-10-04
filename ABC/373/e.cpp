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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> sa = a;
    sort(sa.begin(), sa.end());
    vector<ll> acc(n+1);
    rep(i, 1, n+1) acc[i] = acc[i-1]+sa[i-1];
    
    ll sum = 0;
    rep(i, 0, n) sum += a[i];

    ll rest = k-sum;
    
    vector<ll> ans(n, -1);
    rep(i, 0, n){
        // 残り全票入ったとしてだめならだめ
        {
            ll tmp = a[i]+rest;
            int cnt = sa.end()-upper_bound(sa.begin(), sa.end(), tmp);
            if(cnt >= m) continue;
        }
        // 票数を二分探索
        ll ok = rest, ng = -1;
        while(ok-ng > 1){
            ll mid = (ok+ng)/2;
            ll tmp = a[i]+mid;
            int cnt = sa.end()-upper_bound(sa.begin(), sa.end(), tmp); // 票を得なくても勝てる人
            // 適切に rest-mid 票を分配して、tmp+1 以上の票を得る人を m 人以上にできるか
            if(cnt >= m){
                ng = mid;
                continue;
            }
            int need = m-cnt;
            int r = upper_bound(sa.begin(), sa.end(), tmp)-sa.begin();
            int l = r-need;
            if(l < 0){
                ok = mid;
                continue;
            }
            // cout << i << ' ' << tmp << ' ' << l << ' ' << r << endl;
            ll cost = need*(tmp+1)-(acc[r]-acc[l]);
            // [l, r] に a[i] が入っていたら除く
            if(sa[l] <= a[i]){
                if(l == 0){
                    ok = mid;
                    continue;
                }
                cost -= (tmp+1)-a[i];
                cost += (tmp+1)-sa[l-1];
            }
            // cout << cost << endl;
            if(cost <= rest-mid) ng = mid;
            else ok = mid;
        }
        ans[i] = ok;
    }
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;

    
    return 0;
}