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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<vector<mint>> dp(n+1, vector<mint>(n+1));
    vector<vector<bool>> seen(n+1, vector<bool>(n+1));
    dp[0][0] = 1;
    seen[0][0] = 1;
    auto f = [&](auto self, int N, int K) -> mint {
        if(K < 0 || N < K) return 0;
        if(seen[N][K]) return dp[N][K];
        seen[N][K] = true;
        mint res = 0;
        res += self(self, N-1, K-1);
        res += self(self, N, 2*K);
        return dp[N][K] = res;
    };  
    cout << f(f, n, k).val() << endl;
    
    return 0;
}