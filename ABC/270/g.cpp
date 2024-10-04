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
using mint = modint;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
baby-step giant-step
- N 回繰り返すと一蹴する周期的なある操作 f を s から始めて ? 回行うと g になったとき, ? を求めるアルゴリズム
- f^{sqrt(N)} が求まれば O(sqrt{N}) で求まる
- f^{i*sqrt(N)}(x) を出しておいて, y, f(y), ... , f^{sqrt{N}-1}(y) との一致を調べる
- 一致したとき、差分を取れば ? が求まるという方針

*/

int main(){
    int t; cin >> t;
    while(t--){
        ll p, a, b, s, g; cin >> p >> a >> b >> s >> g;
        mint::set_mod(p);
        if(a == 0){
            // 初項 S, それ以降 B の数列
            if(s == g) cout << 0 << endl;
            else if(b == g) cout << 1 << endl;
            else cout << -1 << endl;
        }else if(a == 1){
            // 一般項 S+Bn の数列
            if(b == 0){
                if(s == g) cout << 0 << endl;
                else cout << -1 << endl;
            }else{
                // (g-s)/b (mod p)
                mint ans = mint(g-s)/b;
                cout << ans.val() << endl; 
            }
        }else{
            mint alpha = mint(-b)/(a-1);
            if(mint(s) == alpha){
                if(alpha == mint(g)) cout << 0 << endl;
                else cout << -1 << endl;
            }else{
                mint goal = (-alpha+g)/(-alpha+s);
                // a^n == goal となる n を求める
                map<int, int> cnt;
                int thle = 32001;
                mint pa = 1;
                rep(i, 0, thle){
                    if(cnt.find(pa.val()) == cnt.end()){
                        cnt[pa.val()] = i;
                    }
                    pa *= a;
                }
                // pa は a^{thle} mod p
                bool ok = false;
                int ans = 0;
                rep(_, 0, thle){
                    if(cnt.find(goal.val()) != cnt.end()){
                        ans += cnt[goal.val()];
                        ok = true;
                        break;
                    }
                    ans += thle;
                    goal /= pa;
                }
                if(ok) cout << ans << endl;
                else cout << -1 << endl;


            }
        }
    }
    
    return 0;
}