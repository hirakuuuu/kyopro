#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/code-formula-2014-qualb/tasks/code_formula_2014_qualB_d

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 1, pw = 1, tmp = 0, tmp2 = 0;
    rep(i, 0, n){
        tmp += a[i];
        tmp2 += a[i]*pw;
        tmp2 %= MOD;
        pw *= 10;
        pw %= MOD;

        if(tmp < 10 || i == n-1){
            ans *= tmp2+1;
            ans %= MOD;
            pw = 1;
            tmp = tmp2 = 0;
        }else{
            tmp /= 10;
        }
    }
    cout << (ans+MOD-1)%MOD << endl;
    
    return 0;
}