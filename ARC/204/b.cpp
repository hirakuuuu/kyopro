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

/*
そもそも最小回数を求める問題なら，(i, pi) に辺を張ったグラフについて，各連結成分のサイズ-1の総和が答え
この連結成分ごとに操作を行えば，おのずと最小回数にはなる
nの倍数に操作できるかどうかは区間DPでできて，割った余りが同じところで区切るだけにすれば，O(n^2k^3)まで落ちる
*/

int main(){
    int n, k; cin >> n >> k;
    vector<int> p(n*k);
    rep(i, 0, n*k){
        cin >> p[i]; p[i]--;
    }

    int ans = 0;
    vector<int> seen(n*k);
    rep(i, 0, n*k){
        if(seen[i]) continue;
        int pos = i;
        vector<int> q;
        while(!seen[pos]){
            q.push_back(pos);
            seen[pos] = 1;
            pos = p[pos];
        }
        int m = (int)q.size();
        if(m == 1) continue;

        vector<vector<int>> dp(m+1, vector<int>(m+1));
        rrep(l, m-1, 0){
            vector<int> same;
            rep(j, l+1, m){
                if(q[l]%n == q[j]%n) same.push_back(j);
            }
            rep(r, l+1, m+1){
                dp[l][r] = dp[l+1][r];
                for(auto nr: same){
                    if(nr < r) chmax(dp[l][r], dp[l+1][nr+1]+dp[nr][r]+1);
                }
            }
        }
        ans += dp[0][m];
    }
    cout << ans << endl;
    
    return 0;
}