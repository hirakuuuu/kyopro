#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc344/tasks/abc344_d

int main(){
    string t; cin >> t;
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<string>> s(n);
    rep(i, 0, n){
        cin >> a[i];
        rep(j, 0, a[i]){
            string ss; cin >> ss;
            s[i].push_back(ss);
        }
    }

    vector<int> dp(t.size()+1, IINF);
    dp[0] = 0;
    rep(i, 0, n){
        vector<int> dp_ = dp;
        rep(j, 0, a[i]){
            if(t.size() < s[i][j].size()) continue;
            rep(k, 0, t.size()-s[i][j].size()+1){
                if(t.substr(k, s[i][j].size()) == s[i][j]){
                    chmin(dp[k+s[i][j].size()], dp_[k]+1);
                }
            }
        }
        // rep(j, 0, t.size()){
        //     cout << dp[j] << ' ';
        // }
        // cout << endl;
    }

    if(dp[t.size()] != IINF) cout << dp[t.size()] << endl;
    else cout << -1 << endl;

    return 0;
}