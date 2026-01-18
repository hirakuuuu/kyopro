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
    int n; cin >> n;
    vector<int> x(n);
    rep(i, 0, n) cin >> x[i];

    int ans = 1;
    rep(i, 1, 1<<n){
        int pre = -1;
        int diff = -1;
        bool ok = true;
        rep(j, 0, n){
            if((i>>j)&1){
                if(pre == -1){
                    pre = x[j];
                }else if(diff == -1){
                    diff = x[j]-pre;
                }else if(diff != x[j]-pre){
                    ok = false;
                }
                pre = x[j];
            }
        }
        if(ok) chmax(ans, __popcount(i));
    }
    cout << ans << endl;
    return 0;
}