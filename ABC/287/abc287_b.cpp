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
// https://atcoder.jp/contests/abc287/tasks/abc287_b

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n), t(m);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, m) cin >> t[i];

    int ans = 0;
    rep(i, 0, n){
        bool f = false;
        rep(j, 0, m){
            if(s[i].substr(3, 3) == t[j]) f = true;
        }
        ans += f;
    }
    cout << ans << endl;
    
    return 0;
}