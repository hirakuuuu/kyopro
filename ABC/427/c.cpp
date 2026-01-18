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
    int m; cin >> m;
    vector<int> u(m), v(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i]; u[i]--, v[i]--;
    }

    int ans = m;
    rep(i, 1, (1<<n)-1){
        int cnt = 0;
        rep(j, 0, m){
            if(((i>>u[j])&1) == ((i>>v[j])&1)) continue;
            cnt++;
        }
        chmin(ans, m-cnt);
    }
    cout << ans << endl;
    return 0;
}