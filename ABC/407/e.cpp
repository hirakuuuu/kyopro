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
正しいかっこ列の累積和条件の同値な言いかえ
- 全ての i について，i 番目までに '(' が ceil(i/2) 個以上ある．

よって，最初の1個は０にできないとして，２個ずつ追加して，最も大きいものを足していくだけでよい
*/

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans; cin >> ans;
        priority_queue<ll> que;
        rep(i, 1, n){
            ll a1, a2; cin >> a1 >> a2;
            que.push(a1);
            que.push(a2);
            ans += que.top(); que.pop();
        }
        int dummy; cin >> dummy;
        cout << ans << endl;
    }
    return 0;
}