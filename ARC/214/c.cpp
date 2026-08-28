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

int main(){
    int n; cin >> n;
    vector<int> p(n);
    int sum = 0;
    rep(i, 0, n){
        cin >> p[i];
        sum += p[i];
    }
    if(sum%2 == 1){
        cout << 0 << endl;
        return 0;
    }

    vector<mint> dp(100005);
    dp[0] = 1;
    rep(i, 0, n){
        rrep(j, 100000-p[i], 0){
            dp[j+p[i]] += dp[j];
        }
    }
    mint x = dp[sum/2];
    cout << (x*x-2*x).val() << endl;


    return 0;
}