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
// https://atcoder.jp/contests/abc297/tasks/abc297_d

int main(){
    ll a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    ll cnt = 0;
    while(a != b){
        if(a > b) swap(a, b);
        
        cnt += b/a - (b%a == 0);
        b = b%a+a*(b%a == 0);

        
    }

    cout << cnt << endl;

    
    return 0;
}