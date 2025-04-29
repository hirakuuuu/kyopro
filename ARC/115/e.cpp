#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
包除原理，愚直にやると O(n^2) になるが，
区間最小値が同じところをまとめて処理する（cartesian tree のイメージ）
*/

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<mint> dp(n+1);
    dp[0] = 1;
    stack<pair<int, mint>> stc;
    mint sum = 0;
    rep(i, 0, n){
        mint tmp = -dp[i];
        while(!stc.empty() && stc.top().first >= a[i]){
            auto [val, num] = stc.top(); stc.pop();
            sum -= val*num;
            tmp += num;
        }
        sum += tmp*a[i];
        stc.push({a[i], tmp});
        dp[i+1] = sum;
    }

    if(n&1) dp[n] = -dp[n];
    cout << dp[n].val() << endl;
    
    return 0;
}