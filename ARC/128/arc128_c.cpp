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
// https://atcoder.jp/contests/arc128/tasks/arc128_c

int main(){
    ll n;
    double m, s; cin >> n >> m >> s;
    vector<double> a(n+1), sa(n+1);
    double total = 0.0;
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) sa[i] = sa[i-1]+a[i];
    rep(i, 1, n+1) total += a[i];

    double ans = 0.0;
    ll r = n;
    while(r > 0){
        double ma = a[r];
        int mi = r-1;
        rrep(i, r-1, 0){
            if(ma < (double)(sa[r]-sa[i])/(r-i)){
                ma = (sa[r]-sa[i])/(r-i);
                mi = i;
            }
        }
        double x = min(m, s/(r-mi));
        ans += (sa[r]-sa[mi])*x;
        s -= x*(r-mi);
        r = mi;
    }

    printf("%.10f\n", ans);






    
    return 0;
}