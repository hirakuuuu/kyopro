#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc154/tasks/arc154_a

int main(){
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    rep(i, 0, n){
        if(a[i]-'0' < b[i]-'0') swap(a[i], b[i]);
    }

    ll ans = 0, tmp = 0, cnt = 1;
    rep(i, 0, n){
        tmp += (a[n-i-1]-'0')*cnt;
        tmp %= mod_num;
        cnt *= 10;
        cnt %= mod_num;
    }


    cnt = 1;
    rep(i, 0, n){
        ans += ((tmp*(b[n-i-1]-'0'))%mod_num)*cnt;
        ans %= mod_num;
        cnt *= 10;
        cnt %= mod_num;
    }
    cout << ans << endl;


    
    return 0;
}