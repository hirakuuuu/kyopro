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
// https://atcoder.jp/contests/abc330/tasks/abc330_f

ll f(vector<ll> &x, ll n, ll m){
    ll cnt = 0;
    ll l = 0, r = n-1;
    vector<ll> c = {1, 1}, p = {x[0], x[n-1]};
    while(p[1]-p[0] > m){
        if(c[0] <= c[1]){
            cnt += c[0]*(min(p[1]-m, x[l+1])-p[0]);
            p[0] = min(x[r]-m, x[l+1]);
            c[0]++;
            l++;
        }else{
            cnt += c[1]*(p[1]-max(p[0]+m, x[r-1]));
            p[1] = max(x[l]+m, x[r-1]);
            c[1]++;
            r--;
        }
    }
    return cnt;
}

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll ok = 9e18, ng = -1;
    while(ok-ng > 1){
        ll m = (ok+ng)/2;
        ll cnt = f(x, n, m)+f(y, n, m);
        if(cnt <= k) ok = m;
        else ng = m;
    }

    cout << ok << endl;
    
    return 0;
}