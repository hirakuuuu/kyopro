#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc189/tasks/abc189_e

int main(){
    ll n; cin >> n;
    vector<ll> x(n+1), y(n+1);
    rep(i, 1, n+1) cin >> x[i] >> y[i];

    ll m; cin >> m;
    vector<vector<ll>> op(m);
    rep(i, 0, m){
        ll t, p; cin >> t;
        if(t >= 3) cin >> p;
        op[i] = {i+1, t, p};
    }

    ll q; cin >> q;
    vector<ll> a(q), b(q);
    rep(i, 0, q) cin >> a[i] >> b[i];
    vector<vector<ll>> queri(m+q);
    rep(i, 0, m) queri[i] = op[i];
    rep(i, m, m+q) queri[i] = {a[i-m], 5, b[i-m], i-m};

    sort(queri.begin(), queri.end());

    vector<pll> ans(q);

    ll rotate = 0;
    ll cnt_x = 0, cnt_y = 0;
    ll offset_x = 0, offset_y = 0;
    rep(i, 0, m+q){
        ll t = queri[i][1], p = queri[i][2];
        if(t == 1){
            rotate++;
            rotate %= 4;
        }else if(t == 2){
            rotate--;
            if(rotate < 0) rotate += 4;
        }else if(t == 3){
            if(rotate == 0){
                offset_x = 2*p-offset_x;
                cnt_x = 1-cnt_x;
            }else if(rotate == 1){
                offset_y = 2*p-offset_y;
                cnt_y = 1-cnt_y;
            }else if(rotate == 2){
                offset_x = -2*p-offset_x;
                cnt_x = 1-cnt_x;
            }else{
                offset_y = -2*p-offset_y;
                cnt_y = 1-cnt_y; 
            }
        }else if(t == 4){
            if(rotate == 0){
                offset_y = 2*p-offset_y;
                cnt_y = 1-cnt_y;
            }else if(rotate == 1){
                offset_x = -2*p-offset_x;
                cnt_x = 1-cnt_x;
            }else if(rotate == 2){
                offset_y = -2*p-offset_y;
                cnt_y = 1-cnt_y; 
            }else{
                offset_x = 2*p-offset_x;
                cnt_x = 1-cnt_x;
            }
        }else{
            ll tmp_x = offset_x+(cnt_x ? -1LL : 1LL)*x[p], tmp_y = offset_y+(cnt_y ? -1LL : 1LL)*y[p];
            rep(j, 0, rotate){
                swap(tmp_x, tmp_y);
                tmp_y *= -1;
            }
            ans[queri[i][3]] = {tmp_x, tmp_y};
        }
    }

    rep(i, 0, q) cout << ans[i].first << ' ' << ans[i].second << "\n";
    
    return 0;
}