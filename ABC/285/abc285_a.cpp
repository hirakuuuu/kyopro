#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc285/tasks/abc285_a

int main(){
    int a, b; cin >> a >> b;
    if(b == 2*a or b == 2*a+1) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}