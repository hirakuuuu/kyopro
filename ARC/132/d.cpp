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

/*
01 文字列　→ グリッド上の経路　という対応を考える
- s, t を (0, 0) から (n, m) に移動する経路として考えると, 良い文字列は s, t の経路に囲まれた領域内の経路として考えられる
- この経路の内、曲がる回数が最小となるようなものを選べば良い
- 最初の文字を固定すると、0 の個数が s の個数と t の個数の間に入っていれば良いということが分かるので、貪欲に構築できる.

*/

int main(){
    int n, m; cin >> n >> m;
    vector<int> s(n+m), t(n+m);
    rep(i, 0, n+m){
        char c; cin >> c;
        s[i] = c-'0';
    }
    rep(i, 0, n+m){
        char c; cin >> c;
        t[i] = c-'0';
    }

    int ans = 0;
    rep(init, 0, 2){
        if(init != s[0] && init != t[0]) continue;
        int s0 = 1-s[0], t0 = 1-t[0], x0 = 1-init;
        int tmp = 0;
        int pre = init;
        rep(i, 1, n+m){
            if(s[i] == 0) s0++;
            if(t[i] == 0) t0++;
            if(pre == 0){
                if(min(s0, t0) <= x0+1 && x0+1 <= max(s0, t0)){
                    x0++;
                    tmp++;
                }else{
                    pre = 1;
                }
            }else{
                if(min(s0, t0) <= x0 && x0 <= max(s0, t0)){
                    tmp++;
                }else{
                    x0++;
                    pre = 0;
                }
            }
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}