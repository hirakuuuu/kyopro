#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc083/tasks/arc088_b

int main(){
    string s; cin >> s;
    int n = s.size();
    string t = '0'+s;
    vector<int> neq(n+1);
    rep(i, 1, n+1) neq[i] = (t[i] != t[i-1]);

    int ans = n;
    rep(i, 2, n+1){
        if(neq[i]) chmin(ans, max(i-1, n-i+1));
    }
    cout << ans << endl;
    
    return 0;
}