#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc250/tasks/abc250_f

int main(){
    int n; cin >> n;
    vector<ll> x(2*n), y(2*n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        x[i+n] = x[i];
        y[i+n] = y[i];
    }
    // auto dist = [&](int i, int j) -> ld {
    //     return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    // };
    auto area = [&](int i, int j, int k) -> ll {
        if(i == j || j == k || k == i) return 0LL;
        ll x1 = x[i]-x[k], y1 = y[i]-y[k];
        ll x2 = x[j]-x[k], y2 = y[j]-y[k];
        return abs(x1*y2-x2*y1);
    };
    ll s = 0LL;
    rep(i, 1, n-1){
        s += area(0, i, i+1);
    }
    int r = 1;
    ll tmp = 0, ans = 9e18;
    rep(l, 0, n){
        while(4*tmp < s){
            tmp += area(l, r%n, (r+1)%n);
            r++;
        }
        chmin(ans, abs(s-4*tmp));
        if(r-l > 2){
            tmp -= area(l, (r-1+n)%n, r%n);
            chmin(ans, abs(s-4*tmp));
            tmp += area(l, (r-1+n)%n, r%n);
        }
        tmp -= area(l, (l+1)%n, r%n);
    }
    cout << ans << endl;



    
    return 0;
}