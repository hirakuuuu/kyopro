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
    int n; cin >> n;
    vector<int> p(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }

    vector<vector<mint>> memo(n+1, vector<mint>(n+1));
    vector<vector<bool>> done(n+1, vector<bool>(n+1));
    auto f = [&](auto self, int l, int r) -> mint {
        if(done[l][r]) return memo[l][r];
        done[l][r] = true;
        
        if(r-l <= 1) return memo[l][r] = 1;
        mint res = self(self, l+1, r);
        rep(i, l+1, r){
            if(p[l] < p[i]){
                res += self(self, l+1, i)*self(self, i, r);
            }
        }
    // cout << l << ' ' << r << ' ' << res.val() << endl;

        return memo[l][r] = res;
    };
    mint ans = f(f, 1, n);
    cout << ans.val() << endl;
    
    return 0;
}