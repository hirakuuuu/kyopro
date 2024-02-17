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
// https://atcoder.jp/contests/abc341/tasks/abc341_d

int main(){
    ll n, m, k; cin >> n >> m >> k;
    if(n > m) swap(n, m);
    ll l = lcm(n, m);


    ll ok = 9e18, ng = 0;
    if(n == 1){

    }else{

    }
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        ll cnt_n = mid/n;
        ll cnt_m = mid/m;
        ll cnt_l = mid/l;
        if(cnt_n+cnt_m-2*cnt_l >= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}