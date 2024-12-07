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
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
two-sat の練習問題

参考: https://qiita.com/sysdev/items/c6b707666541bacd22bf 

(b \and \not a+n) \or (\not b \and a+n)
\to 
(b \or a+n) \and (\not b \or \not a+n)

こうすると、2-sat に帰着されてうれしい
*/

int main(){
    int n, m; cin >> n >> m;
    two_sat ts(2*n);
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c; a--, b--;
        if(c == 0){
            // a は b を正直者と言っている
            ts.add_clause(b, false, a+n, true);
            ts.add_clause(b, true, a+n, false);

            // ts.add_clause(a+n, false, b, false);
            // ts.add_clause(a+n, true, b, true);
        }else{
            // a は b を嘘つきと言っている
            ts.add_clause(b, false, a+n, false);
            ts.add_clause(b, true, a+n, true);

            // ts.add_clause(a+n, false, b, true);
            // ts.add_clause(a+n, true, b, false);
        }
    }

    if(!ts.satisfiable()){
        cout << -1 << endl;
        return 0;
    }
    vector<bool> ans = ts.answer();
    rep(i, 0, n) cout << (ans[i]^ans[i+n]);
    cout << endl;
    
    
    return 0;
}