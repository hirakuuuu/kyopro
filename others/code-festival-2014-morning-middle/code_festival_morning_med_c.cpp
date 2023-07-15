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
// https://atcoder.jp/contests/code-festival-2014-morning-middle/tasks/code_festival_morning_med_c

int main(){
    double p;
    ll n;
    cin >> p >> n;

    double odd = p;
    double ans = 0.0;
    while(n){
        if(n%2 == 1){
            ans = (1.0-ans)*odd+ans*(1.0-odd);
        }
        n /= 2;
        odd = 2.0*odd*(1.0-odd);
    }

    printf("%.12f\n", ans);
    
    return 0;
}