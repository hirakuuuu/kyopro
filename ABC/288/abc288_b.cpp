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
// https://atcoder.jp/contests/abc288/tasks/abc288_b


int main(){
    int n, k; cin >> n >> k;
    string s[n];
    rep(i, 0, n) cin >> s[i];
    sort(s, s+k);
    rep(i, 0, k) cout << s[i] << endl;


    
    return 0;
}