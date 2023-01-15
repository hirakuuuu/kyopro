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
// https://atcoder.jp/contests/abc285/tasks/abc285_b

int main(){
    int n; cin >> n;
    string s; cin >> s;
    rep(i, 1, n){
        int ans = -1;
        rep(j, 0, n-i){
            if(s[j] == s[j+i]) break;
            ans = j;
        }
        cout << ans+1 << endl;
    }
    
    return 0;
}