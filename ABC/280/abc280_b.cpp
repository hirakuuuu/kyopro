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
// https://atcoder.jp/contests/abc280/tasks/abc280_b

int main(){
    int n; cin >> n;
    vector<ll> s(n);
    rep(i, 0, n) cin >> s[i];

    vector<ll> a(n);
    a[0] = s[0];
    rep(i, 1, n) a[i] = s[i]-s[i-1];
    rep(i, 0, n){
        cout << a[i] << ' ';
    }
    cout << endl;
    
    return 0;
}