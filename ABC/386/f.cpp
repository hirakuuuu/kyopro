#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int k; cin >> k;
    string s, t; cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    
    if(abs(n-m) > k){
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> pt(26);
    rep(i, 0, m){
        pt[t[i]-'a'].push_back(i);
    }
    rep(i, 0, 26){
        pt[i].push_back(IINF);
    }

    vector<vector<int>> nx(26, vector<int>(m+1, IINF));
    rep(j, 0, 26){
        rrep(i, m-1, 0){
            if(t[i]-'a' == j) nx[j][i] = i;
            else nx[j][i] = nx[j][i+1];
        }
    }

    vector<vector<int>> dp(k+1, vector<int>(k+1, IINF));
    dp[0][0] = 0;
    rep(i, 0, n){
        int tmp = s[i]-'a';
        vector<vector<int>> ndp(k+1, vector<int>(k+1, IINF));
        rep(j, 0, k+1) rep(l, 0, j+1){
            if(dp[j][l] == IINF) continue;
            // なにもしない
            if(nx[tmp][dp[j][l]] < m) chmin(ndp[j][l], nx[tmp][dp[j][l]]+1);
            // 削除
            if(j < k) chmin(ndp[j+1][l+1], dp[j][l]);
            // 変更
            if(j < k && dp[j][l] < m) chmin(ndp[j+1][l], dp[j][l]+1);
        }
        swap(dp, ndp);
        //     rep(j, 0, k+1) rep(l, 0, j+1){
        // cout << j << ' ' << l << ' ' << dp[j][l] << endl;
        //     }
    }

    rep(j, 0, k+1) rep(l, 0, j+1){
        // cout << j << ' ' << l << ' ' << dp[j][l] << endl;
        if(dp[j][l] == IINF) continue;
        if(abs((n-l)-m) <= k-j){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}