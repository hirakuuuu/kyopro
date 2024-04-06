#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, x; cin >> n >> x;
    vector<vector<ll>> a(n);
    rep(i, 0, n){
        int l; cin >> l;
        a[i].resize(l);
        rep(j, 0, l){
            cin >> a[i][j];
        }
    }

    auto dfs = [&](auto self, int ind, ll tmp) -> int {
        int res = 0;
        if(ind == n){
            return tmp == x;
        }
        for(auto aa: a[ind]){
            if(tmp > x/aa) continue;
            res += self(self, ind+1, tmp*aa);
        }
        return res;
    };
    cout << dfs(dfs, 0, 1LL) << endl;
    
    return 0;
}