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
// https://atcoder.jp/contests/abc289/tasks/abc289_d

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int m; cin >> m;
    vector<int> b(m);
    rep(i, 0, m) cin >> b[i];
    int x; cin >> x;

    vector<int> moti(x+1);
    rep(i, 0, m){
        moti[b[i]] = 1;
    }


    vector<int> dp(x+1);
    dp[0] = 1;
    rep(i, 0, x+1){
        if(!moti[i] and dp[i]){
            rep(j, 0, n){
                if(i+a[j] <= x) dp[i+a[j]] = 1;
            }
        }
    }

    if(dp[x]) cout << "Yes" << endl;
    else cout << "No" << endl;

    
    return 0;
}