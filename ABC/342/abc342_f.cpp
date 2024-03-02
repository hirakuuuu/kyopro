#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
// https://atcoder.jp/contests/abc342/tasks/abc342_f

int main(){
    ll n, l, d; cin >> n >> l >> d;
    vector<long double> p(n+d+2);
    p[0] = 1.0;
    p[1] = -1.0;
    rep(i, 0, l){
        p[i+1] += p[i];
        p[i+1] += p[i]/d;
        p[i+d+1] -= p[i]/d;
        p[i] = 0;
    }
    rep(i, l, n+d+1) p[i+1] += p[i];
    long double acc = 0.0;
    rep(i, n+1, n+d+1) acc += p[i];
    vector<long double> q(n+d+2);
    long double tmp = p[0];
    rep(i, 1, n+d+1){
        q[i] = tmp+acc;
        tmp += p[i];
    }
    rep(i, n+1, n+d+1) q[i] = 0.0;

    vector<long double> r(n+d+2);
    r[n+d] = q[n+d];
    tmp = r[n+d];
    rrep(i, n+d-1, 0){
        r[i] = max(q[i], tmp/d);
        tmp += r[i];
        if(n+d >= i+d) tmp -= r[i+d];
    }
    printf("%.10Lf\n", r[0]);
    return 0;
}