#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
// 問題
// https://atcoder.jp/contests/abc006/tasks/abc006_3


int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, n+1){
        int l = m-3*i;
        if(l%2 == 0){
            if(l/4+(l%4 > 0) <= n-i and n-i <= l/2){
                int j = ((n-i)-l/4-(l%4 > 0))*2+(l%4 > 0);
                cout << j << ' ' << i << ' ' << n-i-j << endl;
                return 0;
            }
        }
    }
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    
    return 0;
}