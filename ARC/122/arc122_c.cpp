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
// https://atcoder.jp/contests/arc122/tasks/arc122_c

int main(){
    ll n; cin >> n;

    ll x = 1, y = 0;
    ll cnt = 1;
    while(x < 1000000000000000000){
        if(y >= x){
            x += y;
        }else{
            y += x;
        }
        cnt++;
    }
    cout << cnt << endl;
    cout << x << endl;
    
    return 0;
}