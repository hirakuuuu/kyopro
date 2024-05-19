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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    vector<int> memo(1<<n, -1);
    auto f = [&](auto self, int tmp) -> int{
        if(memo[tmp] != -1) return memo[tmp];
        int res = 0;
        rep(i, 0, n){
            if(!((tmp>>i)&1)) continue;
            rep(j, i+1, n){
                if(!((tmp>>j)&1)) continue;
                if(a[i] == a[j] || b[i] == b[j]){
                    int cur = self(self, tmp-(1<<i)-(1<<j));
                    if(cur == 0) res = 1;
                }
            }
        }
        return memo[tmp] = res;
    };
    if(f(f, (1<<n)-1) == 1) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    
    return 0;
}