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
// https://atcoder.jp/contests/abc224/tasks/abc224_g

int main(){
    long double n, s, t, a, b; cin >> n >> s >> t >> a >> b;
    long double l = floor(-0.5+sqrt(0.25+2.0*n*b/a));
    if(t-l <= s && s <= t){
        printf("%.10Lf\n", (t-s)*a);
    }else if(t-l <= 1.0){
        printf("%.10Lf\n", b*n/t+a*(t-1)/2.0);
    }else{
        printf("%.10Lf\n", b*n/(l+1.0)+a*l/2.0);
    }
    return 0;
}