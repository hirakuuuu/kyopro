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
// https://atcoder.jp/contests/agc012/tasks/agc012_b

int main(){
    string s; cin >> s;
    ll k; cin >> k;
    int n = (int)s.size();
    vector<ll> y;
    rep(i, 0, n){
        if(s[i] == 'Y') y.push_back(i);
    }
    int m = (int)y.size();
    if(m <= 1){
        cout << m << endl;
        return 0;
    }
    vector<ll> z(m-1);
    rep(i, 0, m-1) z[i] = y[i+1]-y[i]-1;
    vector<ll> acc(m);
    rep(i, 0, m-1) acc[i+1] = acc[i]+z[i]; 
    ll ok = 0, ng = m;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        ll cost = INF;
        ll l_sum = 0, r_sum = 0;
        rep(i, 0, (mid+1)/2) l_sum += z[i]*(i+1);
        rep(i, (mid+1)/2, mid) r_sum += z[i]*(mid-i);
        // zで連続mid個の0を作れるか
        rep(l, 0, m-mid){
            // cout << l << ' ' << l_sum << ' ' << r_sum << endl;
            chmin(cost, l_sum+r_sum);
            int r = l+mid;
            if(l+mid+1 < m){
                l_sum -= acc[l+(mid+1)/2]-acc[l];
                l_sum += z[l+(mid+1)/2]*((mid+1)/2);
                // cout << l+mid << ' ' << l+(mid+1)/2 << endl;
                r_sum += acc[l+mid+1]-acc[l+(mid+1)/2+1];
                r_sum -= z[l+(mid+1)/2]*(mid/2);
            }
        }
        // cout << cost << endl;
        if(cost <= k) ok = mid;
        else ng = mid;
    }
    cout << ok+1 << endl;
    return 0;
}